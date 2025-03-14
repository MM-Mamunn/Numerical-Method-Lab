///By taking any polynomial as input
/// Write a program to find the root of the equation x3 – 9x + 1 = 0, correct to 3 decimal places, by using the bisection method.

#include <bits/stdc++.h>
using namespace std;

double eps = 0.005;

double f_x(double x,vector<double>v)
{

    double ans = 0;
    for(int i = v.size() - 1;i >=0;i--)
    {
        if(v[i])
        {
            double t = 1;
            for( int p = 1 ;p <= i;p++)
                t *= x;
            ans += v[i] * t;
        }

    }
    return ans;
}
int main()
{
    int n ;
    cout<<"Enter the degree of the polynomial:";
    cin>>n;
    vector<double>c(n + 1);
    for( int  i = n ; i >= 0; i--)
    {
        cout<<"Enter the coefficient of x^"<<i<<" :";
        cin>>c[i];
    }
    double largest = 3.0;
    double smallest = 2.0;
    while (true)
    {
        double diff = fabs(largest - smallest);
        if (diff <= eps)
            break;

        double mid = (largest + smallest) / 2.00;
        if (f_x(mid,c) < 0.0)
            smallest = mid;
        else
            largest = mid;
    }
    cout << fixed << setprecision(9) << smallest << endl;
}
/*
Input:
3
1
0
-9
1
Output:
2.941406250
*/
