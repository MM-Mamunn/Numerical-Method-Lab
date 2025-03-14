
///By taking any polynomial as input
///Write a program to find the root of the equation x3 – 5x2 –29 = 0, correct to 3 decimal places, by using secant method.

/*
Secant Method
1. Decide two initial points x1 and x2 and required accuracy level E.
2. Compute f1 = f (x1) and f2 = f (x2)
3. Compute x3 = x2 - (f2 * (x2 - x1)) / (f2 - f1);
4. If |x3- x2| > E, then
set x1 = x2 and f1 = f2
set x2 = x3 and f2 = f(x3)
go to step 3
Else
set root = x3
print results
5. Stop.
*/

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


int main()
{
int n ;
cout<<"Enter the degree of the polynomial:";
cin>>n;
vector<double>c(n + 1);
for( int  i = n ; i >= 0;i--)
{
    cout<<"Enter the coefficient of x^"<<i<<" :";
    cin>>c[i];
}
double x1 = 4.0, x2 = 2.0;//Initial estimate
double fx1 = f_x(x1,c), fx2 = f_x(x2,c);
double x3 = x2 - (fx2 * (x2 - x1)) / (fx2 - fx1);
while(abs(x3 - x2) > eps)
{
    x1 = x2;
    x2 = x3;
    fx1 = fx2;
    fx2 = f_x(x2,c);
    x3 = x2 - (fx2 * (x2 - x1)) / (fx2 - fx1);
}
cout<<fixed<<setprecision(3)<<x3<<endl;
}


/*
Input:
3
1
-5
0
-29
Output: 5.848

*/
