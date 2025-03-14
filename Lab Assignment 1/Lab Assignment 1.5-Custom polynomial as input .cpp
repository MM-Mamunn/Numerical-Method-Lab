///By taking any polynomial as input
//Write a program to find all the roots of the equation x3 - 6x + 4 = 0, correct to 3 decimal places. [Use bisection method].

#include <bits/stdc++.h>
using namespace std;
double eps = 0.001;

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

double bisection_root(double x1, double x2,vector<double>v)
{
    while(fabs(x1 - x2) > eps)
    {
        double mid = ( x1 + x2)/2.00;
        if(f_x(mid,v) * f_x(x1,v) < 0.0)
            x2 = mid;
        else
            x1 = mid;
    }
    return x2;
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

    double lower , upper , x ;///boundary and increment
   cout<<"Enter the lower boundary: ";cin>>lower;
   cout<<"Enter the upper boundary: ";cin>>upper;
   cout<<"Enter the increment span: ";cin>>x;
    double x2 = lower, x1 = lower;

    while(x2 < upper)
    {
        x1 = lower, x2 = lower + x;
        double f1 = f_x(x1,c),f2 =f_x(x2,c);
        lower = x2 + 0.00000001;
        if((f1 * f2) > 0)
        {
            continue;
        }

        cout<<bisection_root(x1, x2,c)<<endl;
    }
}
/*
Input:
3
1
0
-6
4
-100.0
100.0
1.0
Output:
-2.73125
0.732812
2.00078
*/
