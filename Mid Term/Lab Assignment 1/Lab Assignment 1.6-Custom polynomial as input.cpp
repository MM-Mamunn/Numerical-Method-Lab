//Write a program to find the root of the equation x3 - 6x + 4 = 0, correct to 3 decimal places, by using Newton-Raphson method.
//By taking Custom polynomial
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
double f_x(double x, vector<double>c) {
    int n = c.size();
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += 1.00 * (c[i] * pow(x, i));
    }
    return result;
}

///Find f'(x)
double Df_x(double x, vector<double>c)
{
     int n = c.size();
    double result = 0.0;
    for (int i = 1; i < n; ++i) { // Start from 1 since the derivative of x^0 is 0
        result += 1.00 *(i * c[i] * pow(x, i - 1));
    }
    return result;

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

    double x1 = 0;///assumption
    cout<<"Enter Assumption x0: ";
    cin>>x1;
    ;

    double x2 = x1 - f_x(x1,c)/ Df_x(x1,c);
    while(abs(x2 - x1) > E )
    {
        x1 = x2;
        x2 = x1 - f_x(x1,c)/ Df_x(x1,c);

    }
    cout<<fixed<<setprecision(4)<<x1<<endl;
}
/*
Input:
2
1
-3
2
0
Output:
1.0000
*/
