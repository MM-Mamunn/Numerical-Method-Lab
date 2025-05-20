/*
The following values of f (x) are given.
     x              1     2     3       4        5
   y = f(x)     1     8    27     64     125
Write a program to find difference table for the above values.

*/
///Forward Difference Table

#include<bits/stdc++.h>

using namespace std;


void Print(vector <double> x)
{
     for(auto a : x)
            cout<<a<<' ';
        cout<<'\n';
}

double fact(int n)
{
    long long ans = 1;
    for(long  long i = 2  ; i <= n ;i++)
        ans *= i;
    return ans;
}
int main()
{
    //equations of erivatives u = 1 , u (u - 1) = 2u - 1, u ( u - 1 ) ( u - 2 ) = 4u^3 - 18u^2 + 22u + 6 ...........
    vector<vector<double>> f_derivatives_eqn = {
    /// coefficient in reverse order where i'th element is the coefficient of u^i
    {1},
    {-1,2},
    {2,-6,3},
    {6,22,-18,4}
    };

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
    diff[0] = y;
    for( int i = 1; i < n ;i++ )
    {
        for( int j = 1 ; j < diff[i - 1].size() ; j++)
        {
            diff[i].push_back(diff[i - 1][j] - diff[i - 1][j - 1]);
        }
    }
//    cout<<"x : ";
//    Print(x);
//    cout<<"y : ";
//    Print(y);
//    for( int i = 1 ; i <n ;i++)
//    {
//        cout<<"D^"<<i<<": ";
//        Print(diff[i]);
//    }
double first_derivative , x0, h = x[1] - x[0];
cout<<"Enter x0: ";
cin>>x0;

double u = (1.00*(x0 - x[0]))/ (h * 1.00);

for( int i = 1; i < n ;i++)
{
    double temp =0;
    for( int j = 0 ; j <= f_derivatives_eqn[i-1].size(); j++)
    {
       temp += (1.00 * pow(u, j)) * f_derivatives_eqn[i-1][j] ;
    }

    first_derivative += (diff[i][0] * temp) / fact(i);
}
first_derivative /= (h * 1.00);
cout<<"First derivative : "<<first_derivative<<endl;
}

/*
Input:
5
1 2 3 4 5
1 8 27 64 125
1.5
Output:
6.75
*/
