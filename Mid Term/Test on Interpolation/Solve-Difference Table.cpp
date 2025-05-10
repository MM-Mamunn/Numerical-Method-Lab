/*
The following values of f (x) are given.


     x              1    2     3       4       5
   y =f(x)     1     8   27     64     125

Write a program to find difference table for the above values.
Forward Difference table:
*/

#include<bits/stdc++.h>

using namespace std;


void Print(vector <int> x)
{
     for(auto a : x)
            cout<<a<<' ';
        cout<<'\n';
}
int main()
{
    int n,t;
    cout<<"Enter the number of entries: ";
    cin>>n;
    vector<int>x,y,ans[n + 2];
    for(int i = 0 ; i < n;i++)
    {
        cout<<"x: ";
        Print(x);
        cout<<"Enter x["<<i + 1<<"] : ";
        cin>>t;
        x.push_back(t);
        system("CLS");
    }

    for(int i = 0 ; i < n;i++)
    {
        cout<<"y: ";
        Print(y);
        cout<<"Enter x["<<i + 1<<"] : ";
        cin>>t;
        y.push_back(t);
        system("CLS");
    }
    ans[0] = y;
    for( int i = 1; i < n ;i++ )
    {
        for( int j = 1 ; j < ans[i - 1].size() ; j++)
        {
            ans[i].push_back(ans[i - 1][j] - ans[i - 1][j - 1]);
        }
    }
    cout<<"x : ";
    Print(x);
    cout<<"y : ";
    Print(y);
    for( int i = 1 ; i <n ;i++)
    {
        cout<<"D^"<<i<<": ";
        Print(ans[i]);
    }
}
