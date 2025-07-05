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

    vector<vector<double>>A(5, vector<double>(5, 0));

    for( int i = 1 ; i <= 3; i++)
    {
        for( int j = 1 ; j <= 3; j++)
        {
            cout<<"Enter a"<<i<<j<<" : ";
            cin>>A[i][j];
        }
        cout<<"Enter b"<<i<<": ";
        cin>>A[i][4];
    }
    for( int i = 1; i <= 3 ; i++)
    {
        ///Normalize ith eqn
        double div = A[i][i];
        for( int j = 1 ; j <= 4; j++)
        {
            A[i][j] /= (1.00 * div);
        }
        ///Eliminate xi
        for( int j= 1 ; j <= 3; j++)
        {
            if(i == j)
                continue;
            double sub = (-1.00) * A[j][i];
            for(int k = 1; k <= 4; k++)
            {
                A[j][k] += (sub * A[i][k]);
            }
        }

    }

    for(int i= 1; i <= 3; i++)
    {
        cout<<"x"<<i<<" = "<<A[i][4]<<endl;
    }
}

/*
Input:
2 1 1 10
3 2 3 18
1 4 9 16
Output:
x1 = 7
x2 = -9
x3 = 5
Input:
2 4 -6 -8
1 3 1 10
2 -4 -2 -12
Output:
x1 = 1
x2 = 2
x3 = 3
Input:
1 2 1 8
2 3 4 20
4 3 2 16
Output:
x1 = 1
x2 = 2
x3 = 3
*/
