import React, { useState } from "react";
import { evaluate, derivative, log } from "mathjs";
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  Tooltip,
  CartesianGrid,
  ReferenceDot,
  ReferenceLine,
  Label,
  Scatter,
} from "recharts";

// Helper: Color for each method
const methodColors = {
  Bisection: "#1d4ed8",
  "Newton-Raphson": "#22c55e",
  Secant: "#f59e42",
  "False Position": "#e11d48",
};

export default function App() {
  // *** State for initial guesses as strings (can be '-', etc) ***
  const [initialGuess, setInitialGuess] = useState({ x0: "1.5", x1: "2" });

  const [equation, setEquation] = useState("x^3 - x - 2");
  const [result, setResult] = useState(null);
  const [method, setMethod] = useState("");
  const [comparison, setComparison] = useState(null);
  const [error, setError] = useState("");

  // Convert to numbers *with fallback* only at solve/compare time:
  const parsedGuessX0 = parseFloat(initialGuess.x0);
  const parsedGuessX1 = parseFloat(initialGuess.x1);

  const handleSolve = (methodName) => {
    setMethod(methodName);
    setError("");
    const x0 = isNaN(parsedGuessX0) ? 1.5 : parsedGuessX0;
    const x1 = isNaN(parsedGuessX1) ? 2 : parsedGuessX1;
    const res = solveEquation(equation, methodName, x0, x1);
    if (res.error) setError(res.error);
    setResult(res);
    setComparison(null);
  };

  const handleCompare = () => {
    handleSolve(method); // Reuse handleSolve to set method

    setError("");
    const x0 = isNaN(parsedGuessX0) ? 1.5 : parsedGuessX0;
    const x1 = isNaN(parsedGuessX1) ? 2 : parsedGuessX1;
    const methods = ["Bisection", "Newton-Raphson", "Secant", "False Position"];
    const results = methods.map((m) => solveEquation(equation, m, x0, x1));
    setComparison(results);
  };

  // Evaluate function y=f(x)
  const f = (x) => {
    try {
      const y = evaluate(equation, { x });
      return typeof y === "number" && isFinite(y) ? y : null;
    } catch {
      return null;
    }
  };

  // Chart the function (y) values for display
  const graphData = Array.from({ length: 200 }, (_, i) => {
    const x = -5 + i * 0.1;
    return { x, y: f(x) };
  });

  // SHOW initial guess inputs
  function renderInitialInputs() {
    if (
      method === "Newton-Raphson" ||
      method === "Secant" ||
      method === "False Position"
    ) {
      return (
        <div className="flex gap-3 mb-4 px-3">
          <div>
            <label className="block text-xs font-bold text-gray-700">x₀</label>
            <input
              type="number"
              step="any"
              className="border border-blue-300 px-2 py-1 rounded shadow-sm focus:border-blue-500"
              value={initialGuess.x0}
              onChange={(e) =>
                setInitialGuess((g) => ({ ...g, x0: e.target.value }))
              }
            />
          </div>
          {(method === "Secant" || method === "False Position") && (
            <div>
              <label className="block text-xs font-bold text-gray-700">
                x₁
              </label>
              <input
                type="number"
                step="any"
                className="border border-blue-300 px-2 py-1 rounded shadow-sm focus:border-blue-500"
                value={initialGuess.x1}
                onChange={(e) =>
                  setInitialGuess((g) => ({ ...g, x1: e.target.value }))
                }
              />
            </div>
          )}
        </div>
      );
    }
    return null;
  }

  return (
    <div className="min-h-screen bg-blue-50 p-4 font-sans">
      <div className="max-w-3xl mx-auto bg-white p-6 rounded-2xl shadow-2xl">
        <h1 className="text-3xl font-extrabold mb-2 text-center text-blue-700 tracking-tight">
          Nonlinear Equation Solver
        </h1>
        <div className="text-center text-gray-600 mb-4">
          Visualize how root-finding methods converge to a root! <br />
          Enter your equation and explore each method's process.
        </div>
        <input
          className="border-2 border-blue-200 px-3 py-2 rounded-lg w-full mb-5 font-mono text-blue-900 shadow-md focus:border-blue-400 focus:ring"
          value={equation}
          onChange={(e) => setEquation(e.target.value)}
          placeholder="Enter equation, e.g., log(x) + x^2 - 4"
        />

        <div className="grid grid-cols-2 md:grid-cols-4 gap-3 mb-4">
          {["Bisection", "Newton-Raphson", "Secant", "False Position"].map(
            (m) => (
              <button
                key={m}
                onClick={() => {
                  setMethod(m);
                  setResult(null);
                }}
                className={
                  "px-4 py-2 rounded-lg font-semibold shadow transition " +
                  (method === m
                    ? "bg-gradient-to-r from-blue-600 to-fuchsia-500 text-white scale-105 ring-2 ring-fuchsia-300"
                    : "bg-blue-200 hover:bg-blue-400 text-blue-800")
                }
              >
                {m}
              </button>
            )
          )}
        </div>

        {renderInitialInputs()}

        <div className="flex flex-wrap gap-3 mb-6">
          <button
            onClick={() => handleSolve(method)}
            disabled={!method}
            className={`px-6 py-2 rounded font-bold shadow transition 
              ${
                !method
                  ? "bg-gray-300 text-gray-400 cursor-not-allowed"
                  : "bg-fuchsia-500 hover:bg-fuchsia-700 text-white"
              }`}
          >
            Solve
          </button>

          <button
            onClick={handleCompare}
            className="bg-gradient-to-r from-green-400 to-blue-400 hover:from-green-600 hover:to-blue-500 text-white px-6 py-2 rounded-lg font-bold shadow"
          >
            Compare Methods
          </button>
        </div>

        {error && (
          <div className="text-red-500 font-semibold mb-3">{error}</div>
        )}

        <div className="mb-7">
          {result && (
            <div className="bg-blue-50 border-l-4 border-blue-400 p-4 rounded-lg shadow mb-2">
              <p className="font-bold text-blue-800">
                {result.method}:{" "}
                <span className="font-mono text-black">
                  Root ≈ {result.root?.toFixed(6)}
                </span>{" "}
                <span className="text-gray-700">
                  in {result.iterations} iterations.
                </span>
              </p>
            </div>
          )}
          {comparison && (
            <div className="w-full">
              <table className="w-full text-left border mt-4 bg-blue-100/70 rounded shadow overflow-hidden">
                <thead>
                  <tr>
                    <th className="border px-3 py-1">Method</th>
                    <th className="border px-3 py-1">Root</th>
                    <th className="border px-3 py-1">Iterations</th>
                  </tr>
                </thead>
                <tbody>
                  {comparison.map((res) => (
                    <tr key={res.method}>
                      <td
                        className="border px-2 py-1 font-semibold"
                        style={{ color: methodColors[res.method] }}
                      >
                        {res.method}
                      </td>
                      <td className="border px-2 py-1">
                        {res.root?.toFixed(6)}
                      </td>
                      <td className="border px-2 py-1">{res.iterations}</td>
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
          )}
        </div>

        <div className="mt-6 overflow-x-auto">
          <LineChart width={640} height={340} data={graphData}>
            <CartesianGrid strokeDasharray="3 3" />
            <XAxis
              dataKey="x"
              type="number"
              domain={["auto", "auto"]}
              tickCount={10}
            />
            <YAxis domain={["auto", "auto"]} />
            <Tooltip contentStyle={{ fontSize: 14, fontFamily: "monospace" }} />
            <Line
              type="monotone"
              dataKey="y"
              stroke="#6366f1"
              dot={false}
              strokeWidth={2}
            />

            <ReferenceLine y={0} stroke="gray" strokeDasharray="3 3">
              <Label value="y = 0" position="insideBottomRight" fontSize={12} />
            </ReferenceLine>

            {/* Show initial guess dots */}
            {(method === "Newton-Raphson" ||
              method === "Secant" ||
              method === "False Position") && (
              <>
                {!isNaN(parsedGuessX0) && (
                  <ReferenceDot
                    x={parsedGuessX0}
                    y={f(parsedGuessX0)}
                    r={7}
                    fill="#4f46e5"
                    stroke="#fff"
                    strokeWidth={2}
                  >
                    <Label position="top" fontSize={11} fill="#4f46e5">
                      x₀
                    </Label>
                  </ReferenceDot>
                )}
                {(method === "Secant" || method === "False Position") &&
                  !isNaN(parsedGuessX1) && (
                    <ReferenceDot
                      x={parsedGuessX1}
                      y={f(parsedGuessX1)}
                      r={7}
                      fill="#e11d48"
                      stroke="#fff"
                      strokeWidth={2}
                    >
                      <Label position="top" fontSize={11} fill="#e11d48">
                        x₁
                      </Label>
                    </ReferenceDot>
                  )}
              </>
            )}

            {/* Final root */}
            {result && result.root !== null && isFinite(result.root) && (
              <ReferenceDot
                x={result.root}
                y={0}
                r={9}
                fill="#c026d3"
                stroke="#fff"
                strokeWidth={2}
              >
                <Label
                  value="Root"
                  position="bottom"
                  fill="#c026d3"
                  fontSize={13}
                />
              </ReferenceDot>
            )}
          </LineChart>
        </div>
        {/* Legend/Key */}
        <div className="my-3 px-3 text-gray-600 text-xs grid grid-cols-2 md:grid-cols-4 gap-3">
          <span>
            <span className="mr-2 inline-block rounded-full bg-blue-500 w-3 h-3" />
            Bisection: Endpoints (a,b)
          </span>
          <span>
            <span className="mr-2 inline-block rounded-full bg-fuchsia-500 w-3 h-3" />{" "}
            Mid & Final root
          </span>
          <span>
            <span className="mr-2 inline-block rounded-full bg-green-500 w-3 h-3" />
            Newton/Secant Steps
          </span>
          <span>
            <span className="mr-2 inline-block rounded-full bg-red-500 w-3 h-3" />
            False Position: c
          </span>
        </div>
      </div>
    </div>
  );
}

function solveEquation(equation, method, user_x0 = 1.5, user_x1 = 2) {
  let f, dfExpr, df;
  try {
    f = (x) => evaluate(equation, { x });
    dfExpr = derivative(equation, "x");
    df = (x) => dfExpr.evaluate({ x });
  } catch (err) {
    return {
      method,
      root: null,
      iterations: 0,
      iterSteps: [],
      error: "Invalid input/derivative",
    };
  }

  const tol = 1e-6;
  const maxIter = 100;
  let x0 = user_x0,
    x1 = user_x1;
  let iter = 0;
  let root = null;
  let iterSteps = []; // <-- store progress

  // For global "auto interval" expansion (for bisection/fp fallback)
  let global_smallest = 0,
    global_largest = 0;
  let inc = 1;
  while (f(global_smallest) >= 0) (global_smallest -= inc), (inc *= 2);
  inc = 1;
  while (f(global_largest) <= 0) (global_largest += inc), (inc *= 2);

  if (global_smallest == -Infinity || global_largest == Infinity) {
    console.log("hi", global_smallest, global_largest);
    global_largest = 0;
    global_smallest = 0;
    let inc = 1;
    while (f(global_smallest) >= 0) (global_smallest += inc), (inc *= 2);
    inc = 1;
    while (f(global_largest) <= 0) (global_largest -= inc), (inc *= 2);
  }
  try {
    switch (method) {
      case "Bisection": {
        let smallest = global_smallest;
        let largest = global_largest;
        console.log("Global interval:", smallest, largest);
        for (iter = 0; iter < maxIter; iter++) {
          let mid = (largest + smallest) / 2.0;
          let diff = Math.abs(largest - smallest);
          if (diff <= tol) {
            root = mid;
            break;
          }
          if (f(mid) < 0.0) smallest = mid;
          else largest = mid;
        }
        root = (largest + smallest) / 2.0;
        break;
      }

      case "Newton-Raphson": {
        let x1 = x0; // initial guess
        let x2 = x1 - f(x1) / df(x1);
        for (iter = 0; iter < maxIter; iter++) {
          x1 = x2;
          x2 = x1 - f(x1) / df(x1);
          if (Math.abs(x1 - x2) < tol) break;

          if (Math.abs(df(x1)) < 1e-12) {
            return {
              method,
              root: null,
              iterations: iter,
              iterSteps,
              error: "Zero derivative encountered.",
            };
          }
        }
        root = x2;
        break;
      }

      case "Secant": {
        let sx1 = x0,
          sx2 = x1;

        let fx1 = f(sx1),
          fx2 = f(sx2);
        let sx3 = sx2 - (fx2 * (sx2 - sx1)) / (fx2 - fx1);

        for (iter = 0; iter < maxIter; iter++) {
          fx1 = f(sx1);
          fx2 = f(sx2);
          if (Math.abs(fx2 - fx1) < 1e-14) {
            return {
              method,
              root: null,
              iterations: iter,
              iterSteps,
              error: "Division by near-zero in Secant.",
            };
          }
          sx1 = sx2;
          sx2 = sx3;
          fx1 = fx2;
          fx2 = f(sx2);

          sx3 = sx2 - (fx2 * (sx2 - sx1)) / (fx2 - fx1);

          if (Math.abs(sx3 - sx2) < tol) {
            root = sx3;

            break;
          }

          root = sx3;
        }
        break;
      }

      case "False Position": {
        let fx1 = x0,
          fx2 = x1;
        if (f(fx1) * f(fx2) > 0) {
          fx1 = global_smallest;
          fx2 = global_largest;
        }
        console.log("Global interval:", fx1, fx2);
        let fx0 = fx1 - (f(fx1) * (fx2 - fx1)) / (f(fx2) - f(fx1));
        if (f(fx0) * f(fx1) < 0) fx2 = fx0;
        else fx1 = fx0;

        let fx0_prev = fx0;
        fx0 = fx1 - (f(fx1) * (fx2 - fx1)) / (f(fx2) - f(fx1));

        for (iter = 1; iter <= maxIter; iter++) {
          if (f(fx1) * f(fx0) < 0) fx2 = fx0;
          else fx1 = fx0;
          fx0_prev = fx0;
          fx0 = fx1 - (f(fx1) * (fx2 - fx1)) / (f(fx2) - f(fx1));

          if (Math.abs(fx0_prev - fx0) < tol) {
            root = fx0;
            break;
          }
          root = fx0;
        }
        break;
      }
    }
  } catch (err) {
    return {
      method,
      root: null,
      iterations: iter,
      iterSteps,
      error: "Error: " + err.message,
    };
  }

  return { method, root, iterations: iter, iterSteps };
}
