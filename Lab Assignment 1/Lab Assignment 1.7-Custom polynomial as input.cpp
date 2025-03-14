///By taking any polynomial as input
///Write a program to find the root of the equation x3 - x + 2 = 0, correct to 3 decimal places, by using false position method

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
    double x1 = -2.0, x2 = 1.0;

    double x0 = x1 - (f_x(x1,c) * (x2- x1))/ (f_x(x2,c) - f_x(x1,c));
    if(f_x(x1,c) * f_x(x0,c) < 0.0)
        x2 = x0;
    else x1 = x0;

    double x0_prev = x0;
    int cnt = 1;
    x0 = x1 - (f_x(x1,c) * (x2- x1))/ (f_x(x2,c) - f_x(x1,c));
    while(abs(x0_prev - x0) > E)
    {
        if(f_x(x1,c) * f_x(x0,c) < 0)
            x2 = x0;
        else x1 = x0;
        x0_prev = x0;
        x0 = x1 - (f_x(x1,c) * (x2- x1))/ (f_x(x2,c) - f_x(x1,c));
    }
    cout<<fixed<<setprecision(4)<<x0<<endl;
}

/*
Input:
3
1
0
-1
2
Output:
-1.5214
*/