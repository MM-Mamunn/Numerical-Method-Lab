///Write a program to find all the roots of the equation x3 - 6x + 4 = 0, correct to 3 decimal places. [Use Newton-Raphson method with deflation].

///Copy
///Copy
///Copy



#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Evaluate the polynomial a[0]*x^n + a[1]*x^(n-1) + ... + a[n] via Horner's method
double f(double x, const double a[], int n) {
    double val = a[0];
    for(int i = 1; i <= n; i++) {
        val = val * x + a[i];
    }
    return val;
}

// Evaluate the derivative f'(x) of the polynomial above
// f'(x) = n*a[0]*x^(n-1) + (n-1)*a[1]*x^(n-2) + ... + a[n-1]
double fprime(double x, const double a[], int n) {
    double val = n * a[0];
    for(int i = 1; i < n; i++) {
        val = val * x + (n - i) * a[i];
    }
    return val;
}

// Synthetic division to deflate the polynomial by (x - r)
// After division, the degree is reduced by 1 and the new coefficients overwrite a[]
void syntheticDivision(double a[], int &n, double r) {
    // b[] will hold the result of synthetic division
    double b[20];  // Assume n <= 20 for simplicity
    b[0] = a[0];
    for(int i = 1; i <= n; i++) {
        b[i] = a[i] + r * b[i - 1];
    }
    // b[n] is the remainder (should be close to zero if r is a true root)
    // The quotient coefficients are b[0..n-1]
    n = n - 1; // One degree lower
    for(int i = 0; i <= n; i++) {
        a[i] = b[i]; // Overwrite original coefficients
    }
}

int main() {
    // Our polynomial is x^3 - 6x + 4 = 0
    // Store coefficients in descending powers:
    //    a[0] = 1 (coefficient of x^3)
    //    a[1] = 0 (coefficient of x^2)
    //    a[2] = -6 (coefficient of x^1)
    //    a[3] = 4  (constant term)
    int n = 3; // Current polynomial degree
    double a[4] = {1.0, 0.0, -6.0, 4.0};

    // Parameters for Newton-Raphson
    double tol = 1e-7;
    int maxIter = 1000;

    // We will store up to 3 roots here
    double roots[3];
    int rootCount = 0;

    // Initial guess for the first root
    double x0 = 1.0;

    // Step through polynomial degrees until we reach a linear polynomial
    while(n > 1) {
        // Newton-Raphson to find one root of the current polynomial
        double x = x0;
        for(int i = 0; i < maxIter; i++) {
            double fx  = f(x, a, n);
            double dfx = fprime(x, a, n);
            if(fabs(dfx) < 1e-14) {
                cerr << "Derivative is too small; try another guess or check polynomial." << endl;
                break;
            }
            double xNew = x - fx / dfx;
            if(fabs(xNew - x) < tol) {
                x = xNew;
                break;
            }
            x = xNew;
        }

        // Save this root
        roots[rootCount++] = x;

        // Deflate the polynomial by dividing out (x - root)
        syntheticDivision(a, n, x);

        // Use this root as initial guess for the next root
        x0 = x;
    }

    // Now the polynomial is of degree 1 => a[0]*x + a[1] = 0
    // The final root is simply -a[1] / a[0].
    roots[rootCount++] = -a[1] / a[0];

    // Print all roots, to 3 decimal places
    cout << fixed << setprecision(3);
    for(int i = 0; i < 3; i++) {
        cout << "Root \" << (i + 1) << \" = " << roots[i] << endl;
    }

    return 0;
}
