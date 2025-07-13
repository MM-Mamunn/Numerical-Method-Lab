
#include<bits/stdc++.h>

using namespace std;

double det(vector<vector<double>> &mat)
{
      int det = 0;
    det = mat[1][1] * (( mat[2][2] * mat[3][3] ) - (mat[2][3] * mat[3][2]));
    det -= mat[1][2] * (( mat[2][1] * mat[3][3] ) - (mat[2][3] * mat[3][1]));
    det += mat[1][3] * (( mat[2][1] * mat[3][2] ) - (mat[2][2] * mat[3][1]));

    return det;
}
void solve()
{
    int valid = 1;
    vector<vector<double>>A(4, vector<double>(4, 0));
    vector<double>B(4),answer;
    for( int i = 1 ; i <= 3; i++)
    {
        for( int j = 1 ; j <= 3; j++)
        {

            cin>>A[i][j];
        }
        cin>>B[i];
    }

    double detA = det(A);
    if(fabs(detA - 0.0) < 0.000001 )
    {
        valid = 0;

    }

    vector<double> deter;
    vector<vector<double>>temp;

    for( int i = 1; i <= 3; i++)
    {
        temp = A;
        for(int j = 1; j <= 3 ; j++)
        {
            temp[j][i] = B[j];
        }
        deter.push_back(det(temp));

    }
    deter.push_back(detA);
    for(auto a : deter)
        cout<<(long long)a<<' ';
    cout<<endl;
    if(!valid)
    {
        cout<<"No unique solution\n";
    }
    else
    {
        cout<<"Unique solution: ";
        for(int i = 0 ; i < deter.size() - 1; i ++){
            double ans = (deter[i]/ detA);
            if(fabs (0 - ans) < 0.0001)
                ans = 0;
            cout<<setprecision(3)<<fixed<<ans<<' ';
        }
        cout<<endl;
    }

}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
