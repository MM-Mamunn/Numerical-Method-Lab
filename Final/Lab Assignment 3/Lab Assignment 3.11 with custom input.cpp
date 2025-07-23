/*
Write a program to solve the following system of linear equations by using Jacobi's method.
         83x + 11y  -   4z = 95
           3x +   8y + 29z = 71
           7x + 52y + 13z = 104
*/
/*
remember:
For each row, the absolute value of the diagonal element should be greater than the sum of absolute values of the other elements in the equation. i.e.
		| aii | >  sum(| aij |) for all j and i != j
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
    vector<double>assumption(n + 2);
    for( int i = 1; i <= n; i++)
        assumption[i] = 0.0;
    vector<double>t_assumption(n + 2);

    while(1)
    {
        for( int i = 1; i <= n ; i++)
        {
            double temp = A[i][n + 1] * 1.00;
            for( int j = 1; j<= n; j++)
            {
                if(i != j)
                {
                    temp -= 1.00 * A[i][j] * assumption[j];
                }
            }

            temp /= (1.00 * A[i][i]);
            t_assumption[i] = temp;
        }
        bool f = 0;
        for(int i = 1 ; i <= n ;i++)
        {
            if(fabs(assumption[i] - t_assumption[i]) >0.0001 )
            {
                f = 1;
                break;
            }
        }
        if(!f)
            break;
        assumption = t_assumption;

    }
    for( int i = 1; i<=n; i++)
    {
        cout<<setprecision(2)<<fixed<<"x"<<i<<" = "<<assumption[i]<<endl;
    }
}

/*
Input:
3
5 2 1 12
1 4 2 15
1 2 5 20
Output:
x1 = 1
x2 = 2
x3 = 3
Input:
3
83 11 -4 95
7 52 13 104
2 8 29 71
Output:
x1 = 1.06116
x2 = 1.35696
x3 = 2.00076
*/
