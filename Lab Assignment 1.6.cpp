#include<bits/stdc++.h>

using namespace std;

    /*Newton-Raphson Method

    ex: given f(x)= x^2 - 6x + 4
    thus, f'(x) = 2x - 6 (first derivative)
    fix two point , x1, and x2;
    asume x1 initially and find x2 by,
    x2 = x1 - f(x1) / f'(x1)

    replace x1 by x2 and find x2 again,
    repeat this process untill abs(x2 -x1 ) < E

    */

double E = .0005;

///find f(x1)
double function_x1(double x1)
{
    return (x1 * x1) - (6 * x1) + 4;
}

///find f'(x1)
double function_first_derivative(double x1)
{
    return (2 * x1) - 6.0;
}

int main()
{
    double x1 = 0;///assumption
    double x2 = x1 - function_x1(x1)/ function_first_derivative(x1);
    while(abs(x2 - x1) > E )
    {
       x1 = x2;
       x2 = x1 - function_x1(x1)/ function_first_derivative(x1);
    }
    cout<<fixed<<setprecision(4)<<x1<<endl;
}
