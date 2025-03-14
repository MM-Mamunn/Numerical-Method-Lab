//Write a program to find all the roots of the equation x3 - 6x + 4 = 0, correct to 3 decimal places. [Use bisection method].
#include <bits/stdc++.h>
using namespace std;
double eps = 0.001;

double f_x(double x)
{
    return 1.00 * ( (x * x *x) - (6 * x) + 4);
}

double bisection_root(double x1, double x2)
{
    while(fabs(x1 - x2) > eps)
    {
        double mid = ( x1 + x2)/2.00;
        if(f_x(mid) * f_x(x1) < 0.0)
            x2 = mid;
        else
            x1 = mid;
    }
    return x2;
}

int main()
{
    double lower = -100, upper = 100, x = 1.0;///boundary and increment

    double x2 = lower, x1 = lower;

    while(x2 < upper)
    {
        x1 = lower, x2 = lower + x;
        double f1 = f_x(x1),f2 =f_x(x2);
        lower = x2 + 0.1;
        if((f1 * f2) > 0)
        {
            continue;
        }

        cout<<bisection_root(x1, x2)<<endl;
    }
}

