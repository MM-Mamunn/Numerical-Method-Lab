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
    } from "recharts";

    export default function App() {
    const [equation, setEquation] = useState("x^3 - x - 2");
    const [result, setResult] = useState(null);
    const [method, setMethod] = useState("");
    const [comparison, setComparison] = useState(null);

    const handleSolve = (methodName) => {
    setMethod(methodName);
    const res = solveEquation(equation, methodName);
    setResult(res);
    setComparison(null);
    };

    const handleCompare = () => {
    const methods = ["Bisection", "Newton-Raphson", "Secant", "False Position"];
    const results = methods.map((m) => solveEquation(equation, m));
    setComparison(results);
    };

    const graphData = Array.from({ length: 100 }, (_, i) => {
    const x = -5 + i * 0.1;
    let y = null;
    try {
    y = evaluate(equation, { x });
    } catch {
    y = null;
    }
    return { x, y };
    });

    return (
    <div className="min-h-screen bg-gray-100 p-4 font-sans">
    <div className="max-w-3xl mx-auto bg-white p-6 rounded-xl shadow-xl">
    <h1 className="text-2xl font-bold mb-4 text-center">
      Nonlinear Equation Solver
    </h1>
    <input
      className="border px-3 py-2 rounded w-full mb-4"
      value={equation}
      onChange={(e) => setEquation(e.target.value)}
      placeholder="Enter equation e.g. log(x) + x^2 - 4"
    />
    <div className="grid grid-cols-2 md:grid-cols-4 gap-2 mb-4">
      {[
        "Bisection",
        "Newton-Raphson",
        "Secant",
        "False Position",
      ].map((m) => (
        <button
          key={m}
          onClick={() => handleSolve(m)}
          className="bg-blue-500 hover:bg-blue-600 text-white px-4 py-2 rounded"
        >
          {m}
        </button>
      ))}
    </div>
    <button
      onClick={handleCompare}
      className="bg-green-500 hover:bg-green-600 text-white px-4 py-2 rounded mb-4"
    >
      Compare Methods
    </button>

    {result && (
      <div className="mb-4">
        <p className="font-semibold">
          Method: {result.method}, Root: {result.root?.toFixed(6)}, Iterations: {result.iterations}
        </p>
      </div>
    )}

    {comparison && (
      <table className="w-full text-left border mt-4">
        <thead>
          <tr>
            <th className="border px-2 py-1">Method</th>
            <th className="border px-2 py-1">Root</th>
            <th className="border px-2 py-1">Iterations</th>
          </tr>
        </thead>
        <tbody>
          {comparison.map((res) => (
            <tr key={res.method}>
              <td className="border px-2 py-1">{res.method}</td>
              <td className="border px-2 py-1">{res.root?.toFixed(6)}</td>
              <td className="border px-2 py-1">{res.iterations}</td>
            </tr>
          ))}
        </tbody>
      </table>
    )}

    <div className="mt-6">
      <LineChart width={600} height={300} data={graphData}>
        <CartesianGrid strokeDasharray="3 3" />
        <XAxis dataKey="x" />
        <YAxis domain={['auto', 'auto']} />
        <Tooltip />
        <Line type="monotone" dataKey="y" stroke="#8884d8" dot={false} />
        {result && result.root !== null && (
          <ReferenceDot x={result.root} y={0} r={5} fill="red" stroke="none" />
        )}
      </LineChart>
    </div>
    </div>
    </div>
    );
    }

    function solveEquation(equation, method) {
    let f, df;
    try {
    f = (x) => evaluate(equation, { x });
    df = (x) => derivative(equation, "x").evaluate({ x });
    } catch (err) {
    alert("Invalid equation or unsupported function.");
    return { method, root: null, iterations: 0 };
    }

    const tol = 1e-6;
    const maxIter = 150;
    let a = 1, b = 2, x0 = 1.5;
    let iter = 0;
    let root = null;
    
    let global_smallest = 0, global_largest = 0;
    let inc = 1;

    while(f(global_smallest) >= 0 ){global_smallest = -inc;
      inc *= 2;
    }
    inc = 1;
    while(f(global_largest) <= 0 ){global_largest = inc;
      inc *= 2;
    } 
    try {
    switch (method) {
    case "Bisection":
    // while (iter < maxIter) {
    //   const c = (a + b) / 2;
    //   if (Math.abs(f(c)) < tol) {
    //     root = c;
    //     break;
    //   }
    //   f(a) * f(c) < 0 ? (b = c) : (a = c);
    //   iter++;
    //   root = c;
    // }

///changed

 let smallest = global_smallest;
let largest = global_largest; 

      // console.log("smallest", smallest, "largest", largest);
    while (iter++ < maxIter) {
      let diff =Math.abs(largest - smallest);
        if (diff <= tol){
          root = smallest + (largest - smallest) / 2.00;
          break;
        }

        let  mid = (largest + smallest) / 2.00;
        if (f(mid) < 0.0)
            smallest = mid;
        else
            largest = mid;
    }
root = smallest + (largest - smallest) / 2.00;
    break;


    
    case "Newton-Raphson":
    let x = x0;
    while (iter < maxIter) {
      const fx = f(x);
      const dfx = df(x);
      if (Math.abs(fx) < tol) break;
      x -= fx / dfx;
      iter++;
    }
    root = x;
    break;
    case "Secant":
    let x1 = x0, x2 = x0 + 0.5;
    while (iter < maxIter) {
      const fx1 = f(x1);
      const fx2 = f(x2);
      const x3 = x2 - (fx2 * (x2 - x1)) / (fx2 - fx1);
      if (Math.abs(f(x3)) < tol) {
        root = x3;
        break;
      }
      x1 = x2;
      x2 = x3;
      root = x3;
      iter++;
    }
    break;
    case "False Position":
    while (iter < maxIter) {
      const c = (a * f(b) - b * f(a)) / (f(b) - f(a));
      if (Math.abs(f(c)) < tol) {
        root = c;
        break;
      }
      f(a) * f(c) < 0 ? (b = c) : (a = c);
      root = c;
      iter++;
    }
    break;
    }
    } catch (err) {
    alert("Error during calculation, possibly due to invalid input or domain issues.");
    return { method, root: null, iterations: iter };
    }

    return { method, root, iterations: iter };
    }
