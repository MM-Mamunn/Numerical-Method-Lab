/*
Write a program to calculate the approximate area under the curve y = ∫(1 to 5) log10 x dx                                     by using trapezoidal rule.
Theory:
I =h/2 [y0 + 2 (y1 + y2 + ……….  + yn-1) + yn]
*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
double lo,hi;
cout<<"Enter lower limit: ";
cin>>lo;
cout<<"Enter higher limit: ";
cin>>hi;
int step = 10;
double h = (hi - lo)/ (step *1.00), x = lo;
vector <pair<double,double>>points;
while(x <= hi)
{
    double soln = log10(x);
    points.push_back({x, soln});
    x += h;
//    cout<<x<<' '<<soln<<endl;
}
int n = points.size();
///though points need not to hold the 'x' values.
double ans = points[0].second + points.back().second;
for( int i = 1; i < points.size()-1;i++)
{
    ans += 2.00 * points[i].second;
}
ans *= (h/2.00);
cout<<ans<<endl;
}

/*
Input:
1
5
Output:
1.75307
*/
