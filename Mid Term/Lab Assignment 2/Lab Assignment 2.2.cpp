/*
The following values of f (x) are given.                             
     x              1     2     3       4        5
   y = f(x)     1     8    27     64     125
Write a program to find the values of y when x = 1.7 by using Newton's forward interpolation formula.

*/

#include<bits/stdc++.h>

using namespace std;

int fact( int x)
{
    int ans = 1;
    for(int i = 2; i <= x;i++)
        ans *= i;
    return ans;
}

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
    vector<int>x,y,D[n + 2];
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
    D[0] = y;
    for( int i = 1; i < n ;i++ )
    {
        for( int j = 1 ; j < D[i - 1].size() ; j++)
        {
            D[i].push_back(D[i - 1][j] - D[i - 1][j - 1]);
        }
    }
    cout<<"x : ";
    Print(x);
    cout<<"y : ";
    Print(y);
//     for( int i = 1 ; i <n ;i++)
//    {
//        cout<<"D^"<<i<<": ";
//        Print(D[i]);
//    }
    ///Finished calculation of forward difference table
    double X;
    cout<<"Enter 'x' to find f(x):";
    cin>>X;
    int h = x[1] - x[0];
    double u = (1.00 * (X - x[0]))/h;
    double ans = y[0] * 1.00;

    for( int i = 1 ; i <= n - 1 ;i++)
    {
        double temp_u = u;
        for( int j = 1; j < i;j++)
        {
            temp_u *= (u - (double)j);
        }
        temp_u *= 1.00 *D[i][0];
        temp_u/= 1.00 * fact(i);
        ans += 1.00 * temp_u;
    }
    cout<<"f("<<X<<") = "<<ans<<'\n';
}

/*
Input:
5
1 2 3 4 5
1 8 27 64 125
1.7
Output:
f(1.7) = 4.913
*/

/*
Input:
4
0 1 2 3
1 0 1 10
4
Output:
f(4) = 33.0000
*/

