/*

*/

#include<bits/stdc++.h>

using namespace std;

map<int, double>m ,b;

int n,nn;

vector<double> gauss_ele()
{
    m[0] = nn;
    int it = 0;
    vector<vector<double>>A(n + 3, vector<double>(n + 3, 0));

    for( int i = 1 ; i <= n + 1; i++)
    {
        for( int j = 1 ; j <= n + 1; j++)
        {
            A[i][j] = m[it + j -1];
        }
        ++it;
        A[i][n + 2] = b[i];
    }

///means make 0 to i'th entry of every equation
    for( int i = 1 ; i <= n + 1; i++)
    {
        ///make operation on j'th eqn
        for( int j = i + 1; j <= n + 1; j++)
        {
            double multiplier = ( - ((A[j][i] * 1.00)  /A[i][i]));
            for( int k = 1; k <= n + 2; k++)
            {
                double t = A[i][k] * multiplier;
                A[j][k] +=t;
            }
        }
    }

    vector<double>ans;
    map<int, double>mp;
    for(int i = n + 1 ;  i >= 1;i--)
    {
        double t = 0;
        for( int j= 1; j <= n + 1;j++)
        {
            if( i != j)
            {
                t += mp[j] * A[i][j];
            }
        }
        t = A[i][n + 2] - t;
        t/= (1.00 * A[i][i]);
        mp[i] = t;
    }
    for( int i = 1 ; i <= n + 1;i++)
       ans.push_back(mp[i]);
    return ans;
}
int main()
{
cout<<"Enter the order of the polynomial:";
cin>>n;
cout<<"Enter number of entries:";
cin>>nn;
vector<double>x(nn), y(nn);
for(auto &a : x)cin>>a;
for(auto &a : y){cin>>a;b[1] += a;}
for( int i = 1; i <= 2 *n + 2;i++)
{
    double sum = 0;
    for(auto a : x)
        sum += pow(a, i);
    m[i] = sum;
}

for( int i = 1; i <= n + 1;i++ )
{
    double sum = 0;
    for(int j = 0 ; j < nn;j++)
    {
        sum += pow(x[j], i) * y[j];
    }
    b[i + 1] = sum;
}

auto ans = gauss_ele();
for( int i = 0 ; i < ans.size();i++)
{
    if( !i)
    {
        cout<<"y = "<<((ans[i] >=0) ? "":"-")<<fabs(ans[i]);
    }
    else
    {
        cout<<((ans[i] >=0) ? "+":"-")<<fabs(ans[i]);
        cout<<"x";
        if(i > 1)
            cout<<"^"<<i;
    }
}
cout<<endl;
}

/*
Input:
2
4
2 4 6 8
1.4 2.0 2.4 2.8
Output:
y = 0.75+0.355x-0.0125x^2
Input:
2
4
1 2 3 4
6 11 18 27
Output:
y = 3+2x+1x^2
Input:
1
5
-2 -1 0 1 2
1 2 3 4 5
Output:
The line equation is : y = 3+1x
Input:
1
4
0 2 5 7
-1 5 12 20
Output:
The line equation is : y = -1.13793+2.89655x
*/
