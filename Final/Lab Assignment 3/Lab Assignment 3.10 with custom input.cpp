/*
Write a program to solve the following system of linear equations by using Gauss-Jordan Elimination method.
           x + 2y +   z = 8
           2x + 3y + 4z = 20
           4x + 3y + 2z = 16
*/

#include<bits/stdc++.h>

using namespace std;


int main()
{

    int n;
    cout<<"Enter number of unkown: ";
    cin>>n;
    vector<vector<double>>A(n+2, vector<double>(n+2, 0));

    for( int i = 1 ; i <= n; i++)
    {
        for( int j = 1 ; j <= n; j++)
        {
            cout<<"Enter a"<<i<<j<<" : ";
            cin>>A[i][j];
        }
        cout<<"Enter b"<<i<<": ";
        cin>>A[i][n + 1];
    }
    for( int i = 1; i <= n; i++)
    {
        ///Normalize ith eqn
        double div = A[i][i];
        for( int j = 1 ; j <= n + 1; j++)
        {
            A[i][j] /= (1.00 * div);
        }
        ///Eliminate xi
        for( int j= 1 ; j <= n; j++)
        {
            if(i == j)
                continue;
            double sub = (-1.00) * A[j][i];
            for(int k = 1; k <= n + 1; k++)
            {
                A[j][k] += (sub * A[i][k]);
            }
        }
    }
    for(int i= 1; i <= n; i++)
    {
        cout<<"x"<<i<<" = "<<A[i][n + 1]<<endl;
    }
}

/*
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
Input:
3
1 2 1 8
2 3 4 20
4 3 2 16
Output:
x1 = 1
x2 = 2
x3 = 3
*/
