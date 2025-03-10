#include<bits/stdc++.h>

using namespace std;

/*
False Position method.
for root point(x,y), x = x0 and y = 0;
by placing root point to line equation((f (x2) – f (x1)) / (x2 - x1) = (y- f (x1)) / (x - x1))
we find,
x0 = x1- (f(x1) (x2-x1) ) / (f (x2) – f (x1))
repeat untill the absolute difference between two successive x0 is less then E
*/

double E = .00005;

double function_solve(double x)
{
    return ((x * x * x) - x + 2) * 1.00;
}

int main()
{
    double x1 = -2.0, x2 = 1.0;

    double x0 = x1 - (function_solve(x1) * (x2- x1))/ (function_solve(x2) - function_solve(x1));
    if(function_solve(x1) * function_solve(x0) < 0.0)
        x2 = x0;
    else x1 = x0;

    double x0_prev = x0;
    int cnt = 1;
    x0 = x1 - (function_solve(x1) * (x2- x1))/ (function_solve(x2) - function_solve(x1));
    while(abs(x0_prev - x0) > E)
    {
        if(function_solve(x1) * function_solve(x0) < 0)
            x2 = x0;
        else x1 = x0;
        x0_prev = x0;
        x0 = x1 - (function_solve(x1) * (x2- x1))/ (function_solve(x2) - function_solve(x1));
    }
    cout<<fixed<<setprecision(4)<<x0<<endl;
}
