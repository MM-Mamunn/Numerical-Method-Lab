/*
Write a program to calculate the approximate area under the curve y = ∫(0 to pi/2) esinx dx by using Simpson’s 1/3 rule
*/


#include<bits/stdc++.h>

using namespace std;

double fx(double x)
{
    double ans = sin(x);
    ans = exp(ans);
    return ans;
}
int main()
{
double lo,hi;
cout<<"Enter lower limit: ";
cin>>lo;
cout<<"Enter higher limit: ";
cin>>hi;
int step = 10;
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
    if(i % 2)
        ans += 4 * points[i];
    else
    ans += 2 * points[i];
}
ans *= (h/3.00);
cout<<ans<<endl;
}

/*
Input:
0
1.5708
Output:
3.10439
*/
