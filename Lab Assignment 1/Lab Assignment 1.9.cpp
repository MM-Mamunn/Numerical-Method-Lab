//Write a program to find the quotient polynomial q(x) such that p(x) = (x - 2) q(x) where the polynomial p(x) = x3 - 5x2 + 10x - 8 = 0 has a root at x = 2.

#include <bits/stdc++.h>
using namespace std;



/*
p(x) = (x – xr ) q(x),
bi-1 = ai + xr*bi where, bn = 0 and i = n, n-1, ………….1
*/


int main()
{
    int n;
    cout<<"Enter the degree of polynomial p(x):";
    cin>>n;
    vector<double>p(n + 1),q(n + 1);
    double xr;/// Has a root on this point

    for(int i = n ; i >= 0 ; i--)
    {
        cout<<"Enter the coefficients of x^"<<i<<" :";
        cin>>p[i];
    }
    cout<<"Enter Xr :";
    cin>>xr;

    q[n] = 0;
    for( int i = n - 1; i >= 0; i--)
    {
        q[i] = p[i + 1] + (xr * q[i + 1]);
    }
    cout<<"Quotient Polynomial is : ";
    for( int i = n ; i >= 0; i--)
    {
        if(q[i])
        {
            if(q[i] < 0 and i < (n - 1))
                cout<<"-";
            else if (i < (n - 1))
                cout<<"+";
            if(abs(q[i]) > 1)
                cout<<abs(q[i]);
            if(i)
                cout<<"x";
            if(i > 1)
            {
                cout<<"^"<<i;
            }
        }
    }
    cout<<endl;

}

/*
input:
3
1
-5
10
-8
2
x^2-3x+4
Output:

*/
