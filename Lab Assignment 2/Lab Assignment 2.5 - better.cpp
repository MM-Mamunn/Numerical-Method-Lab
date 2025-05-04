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
    vector<double>D[n + 2],y(n);
    for(int i =0 ; i < n; i++)
    {
        cout<<"Enter x"<<i<<":";
        cin>>x[i];
    }

    for(int i =0 ; i <n; i++)
    {
        cout<<"Enter y"<<i<<":";
        cin>>y[i];
    }
    D[0] = y;
    for( int i = 1 ; i < n ; i++)
    {
        for( int j = 1 ; j < D[i - 1].size(); j++)
        {
            double temp = D[i-1][j] - D[i-1][j -1];
            double temp2 = x[j - 1 + i] - x[j - 1];
            double ans = temp/ temp2;
            D[i].push_back(ans);
        }
    }
    ///Print the table
//    for( int i = 1 ; i < n;i++)
//    {
//        cout<<"D^"<<i<<" :\n";
//        for(auto a : D[i])
//            cout<<a<<' ';
//        cout<<endl;
//    }
    double X ;
    cout<<"Enter x to find f(x) : ";
    cin>>X;
    double ans = D[0][0];
    for(int i = 1 ; i < n; i++)
    {
        double temp = 1.0;
        for( int j = 1 ; j <= i; j++)
        {
            temp *= (X - x[j-1]);
        }
        temp *= D[i][0];
        ans += temp;
    }
    cout<<"f("<<X<<") is "<<ans<<endl;

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
