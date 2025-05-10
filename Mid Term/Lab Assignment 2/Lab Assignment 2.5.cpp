/*
The following values of f (x) are given. Prepare the divided difference table for the following data
            x     1      3     4      6      10
  y  =  f(x)  0     18   58   190   920
Write a program to find the values of y when x = 2.7 by using Newton's divided difference formula.
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter number of tabular points: ";
    int n;
    cin>>n;
    vector<double>x(n);
    vector<pair<double,pair<int,int>>>D[n],Y(n);
    ///y[1] = {x,{f,l}} means x = value, start from f index to l index
    ///f[0, 3] = 2.3 means x = 2.3 and f = 0 , l = 3
    for(int i =0 ; i < n; i++)
    {
        cout<<"Enter x"<<i<<":";
        cin>>x[i];
    }

    for(int i =0 ; i <n; i++)
    {
        cout<<"Enter y"<<i<<":";
        cin>>Y[i].first;
        Y[i].second = {i,i};
    }
    D[0] = Y;
    for( int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j < D[i-1].size(); j++)
        {
            int st = D[i -1][j-1].second.first;
            int stp = D[i -1][j].second.second;
            double diff = (D[i - 1][j].first - D[i - 1][j - 1].first)/(x[stp] - x[st]);
            D[i].push_back({diff,{st,stp}});
        }
    }
    ///End of formation of table


    cout<<"Enter x to find f(x): ";
    double X;
    cin>>X;


    ///f(x) = f(x0) + (x-x0) f[x0,x1] + (x-x0) (x-x1) f[x0,x1,x2]+... ...+ (x-x0) (x-x1).. ... (x-xn-1) f[x0,x1,... ..,xn]
    double ans = 0;
    ans = D[0][0].first;
    for( int i = 1; i < n; i++)
    {
        double temp  = 1.00;
        for( int j = 0; j < i; j++)
        {
            temp *= X - x[j];
        }
        temp *= D[i][0].first;
        ans += temp;
    }
    cout<<"f("<<X<<") is : "<<ans<<'\n';
}
/*
Input 1:
5
5 7 11 13 21
150 392 1452 2366 9702
Output:
f(6) is : 252
Input 2:
5
1      3     4      6      10
0     18   58   190   920
2.7
Output:
f(2.7) is : 9.35463
*/
