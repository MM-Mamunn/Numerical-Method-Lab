/*
Write a program to calculate the approximate area under the curve y = ∫1 x / (1+x2) by using Simpson’s 3/8 rule.
*/


#include<bits/stdc++.h>

using namespace std;

double fx(double x)
{
    double ans = x/(1 + (x * x));
    return ans;
}
int main()
{
double lo,hi;
cout<<"Enter lower limit: ";
cin>>lo;
cout<<"Enter higher limit: ";
cin>>hi;
int step = 30;///totall step(here 30) + 1(lo value) creates 30 line that is multiple of 3.
double h = (hi - lo)/step;
vector<double>points;
points.push_back(fx(lo));
for( int i = 1; i <= step;i++)
{
    lo += h;
  points.push_back(fx(lo));
}
int n = points.size();
double ans = points[0] + points.back();
for( int i = 1; i < points.size() - 1; i++)
{
    if(i % 3)
        ans += 3 * points[i];
    else
    ans += 2 * points[i];
}
ans *= ((3.0 * h)/8.00);
cout<<ans<<endl;
}

/*
Input:
0
1
Output:
0.346589
*/

