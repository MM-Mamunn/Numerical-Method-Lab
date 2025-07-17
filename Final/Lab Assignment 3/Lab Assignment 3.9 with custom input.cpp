/*
Write a program to solve the following system of linear equations by using Gaussian Elimination method.
          2x +  y  +   z = 10
           x  + 4y + 9z = 16
          3x + 2y + 3z = 18
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of unknowns:";
    cin >> n;
    vector<vector<double>> A(n + 2, vector<double>(n + 2, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "Enter a" << i << j << " : ";
            cin >> A[i][j];
        }
        cout << "Enter b" << i << ": ";
        cin >> A[i][n + 1];
    }

    ///A[i][j] += ((-A[i][k]/A[k][k]) * A[][j])

    ///Pivot for n diagonal elements (k = 1 to n)
    for( int k = 1; k <= n; k++)
    {
        ///Eliminate k'th element of i'th row .(i > k and i <=n )
        for( int i = k + 1; i <= n; i++)
        {
            ///For normalization
            double multiplier = (1.0 * A[i][k] )/(A[k][k] * 1.00);
            multiplier *= (-1);
            for( int j = 1 ; j <= n + 1; j++)
            {
                A[i][j] += multiplier * A[k][j];
            }
        }
    }

    map<int, double> m;
    for (int i = n; i >= 1; i--)
    {
        double t = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                t += m[j] * A[i][j];
            }
        }
        t = A[i][n + 1] - t;
        t /= (1.00 * A[i][i]);
        m[i] = t;
    }
    for (int i = 1; i <= n; i++)
        cout << "x1 = " << m[i] << endl;
}

/*
Input:
3
2 1 1 10
3 2 3 18
1 4 9 16
Output:
x1 = 7
x2 = -9
x3 = 5
Input:
5
1 1 1 1 1 15
2 1 1 1 1 16
1 2 1 1 1 17
1 1 2 1 1 18
1 1 1 2 1 19
Output:
x1 = 1
x2 = 2
x3 = 3
x4 = 4
x5 = 5
*/
