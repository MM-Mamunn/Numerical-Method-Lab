/*
The following values of f (x) are given.
     x              1     2     3       4        5
   y = f(x)     1     8    27     64     125
Write a program to find the values of x for which f (x) = 85 by using Lagrange’s inverse interpolation formula.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter number of tabular points: ";
    int n;
    cin>>n;
    double x[n],y[n];
    for(int i =0 ; i < n; i++)
    {
        cout<<"Enter x"<<i<<":";
        cin>>x[i];
    }

    for(int i =0 ; i <n; i++)
    {
        cout<<"Enter y"<<i<<":";
        cin>>y[i];
    }
    cout<<"Enter f(x) to find corresponding x:";
    double Y;
    cin>>Y;
    double ans  = 0;
    for( int i = 0; i<n; i++)
    {
        double temp = 1.00,temp2 = 1.00;
        for( int j = 0 ; j < n; j++)
        {
            if(j == i)
                continue;
            temp *= (Y - y[j]);
            temp2 *= (y[i] -y[j]);
        }
        ans += ((temp* 1.00) /temp2) * x[i];
    }
    cout<<"x for given f(x) is "<<ans<<'\n';

}
/*
Input:
5
1 2 3 4 5
1 8 27 64 125
85
Output:
x for given f(x) is 5.64691
*/
