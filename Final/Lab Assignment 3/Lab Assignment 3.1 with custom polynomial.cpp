/*
The following values of f (x) are given.
     x              1     2     3       4        5
   y = f(x)     1     8    27     64     125
Write a program to find the first derivative and the second derivative of the function tabulated above at the point x = 1.

*/


#include<bits/stdc++.h>

using namespace std;



double fact(int n)
{
    long long ans = 1;
    for(long  long i = 2  ; i <= n ;i++)
        ans *= i;
    return ans;
}

///it find the coefficient of the multiplication, eg:equation(2) = u (u -1)( u -2) = u^3 - 3u^2 + 2u + 0 , returns -> {0,2,-3,1}
vector<double> equation(int n)
{
    vector<long long> poly = {0, 1};
    for( int i = 1; i <= n; i ++)
    {
        map <long long, int>mp;
        for( int j = 0 ; j < poly.size(); j++)
        {
            mp[j + 1] += poly[j];
            mp[j] += (-i) * poly[j];
        }
        poly.clear();
        for( int j = 0 ; j <= i + 1; j ++)
        {
            poly.push_back(mp[j]);
        }

    }
   vector<double> polyy;
   for(auto a : poly)
   {
       polyy.push_back(a * 1.00);
   }
   return polyy;
}

///find the derivative of a given polynomial and returns the coefficient of the derived equation
vector<double> Df_x( vector<double>c)
{
     int n = c.size();
     vector<double> eqn;
    double result = 0.0;
    for (int i = 1; i < n; ++i) { // Start from 1 since the derivative of x^0 is 0
     eqn.push_back(i * c[i] * 1.00);
    }
    return eqn;

}

int main()
{

    int n,t;
    cout<<"Enter the number of entries: ";
    cin>>n;
    vector<double>x,y,diff[n + 2];
    for(int i = 0 ; i < n;i++)
    {
        cout<<"x: ";
        cout<<"Enter x["<<i + 1<<"] : ";
        cin>>t;
        x.push_back(t);
    }

    for(int i = 0 ; i < n;i++)
    {
        cout<<"y: ";
        cout<<"Enter y["<<i + 1<<"] : ";
        cin>>t;
        y.push_back(t);
    }

    //calculate difference table
    diff[0] = y;
    for( int i = 1; i < n ;i++ )
    {
        for( int j = 1 ; j < diff[i - 1].size() ; j++)
        {
            diff[i].push_back(diff[i - 1][j] - diff[i - 1][j - 1]);
        }
    }
    vector<vector<double>> f_derivatives_eqn , f_d_derivatives;

    f_derivatives_eqn.push_back({1});
    for(int i = 1; i < n;i++)
    {
       // find the equation of u(u-1)(u-2)..(u-i)
       vector<double> eqn = equation(i);
      //derivative of an equation
      //f_derivatives_eqn[2] means derivative of u(u-1)(u -2)
      f_derivatives_eqn.push_back(Df_x(eqn));
    }


double first_derivative,second_derivative = 0.0 , x0, h = x[1] - x[0];
cout<<"Enter x0: ";
cin>>x0;

double u = (1.00*(x0 - x[0]))/ (h * 1.00);


for( int i = 1; i < n ;i++)
{
    double temp =0;

    //evaluate the derivative equation assign to del i
    for( int j = 0 ; j < f_derivatives_eqn[i-1].size(); j++)
    {
       temp += (1.00 * pow(u, j)) * f_derivatives_eqn[i-1][j] ;
    }
    first_derivative += (diff[i][0] * temp) / fact(i);
}
first_derivative /= (h * 1.00);

cout<<"First derivative : "<<first_derivative<<endl;


//similarly simulate the formula for 2nd derivative
for( int i = 2 ; i < n ;i++)
{
    vector<double> temp = Df_x(f_derivatives_eqn[i -1]);
    double tempp = 0;
    for( int j = 0 ; j < temp.size(); j++)
    {
        tempp += (1.00 * pow(u , j)) * temp[j];
    }
    second_derivative += (diff[i][0]  * tempp) / fact(i);
}
second_derivative /= (1*h*h);
cout<<"Second derivative : "<<second_derivative<<endl;

}

/*
Input:
5
1 2 3 4 5
1 8 27 64 125
1
Output:
First derivative : 3
Second derivative : 6
*/
