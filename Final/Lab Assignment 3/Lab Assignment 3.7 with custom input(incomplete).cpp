/*
Write a program to solve the following system of linear equations by using Matrix inversion method.
          x +  y  +   z = 1
          x + 2y + 3z = 6
          x + 3y + 4z = 6
*/


#include<bits/stdc++.h>

using namespace std;


double det(vector<vector<double>> &M)
{
    int n = M.size() - 1;
    if (n == 1)
        return M[1][1];
    if (n == 2)
        return M[1][1]*M[2][2] - M[1][2]*M[2][1 ];

    double ans = 0.0;
    for( int i = 1; i <= n ; i++)
    {
        int s = i,s2 = i;
        double mul = 1.0,mul2 = 1.0;
        for( int j = 1; j <= n ; j++)
        {
            mul *= M[j][s];
            mul2 *= M[j][s2];
            ++s;
            --s2;
            if(s == (n + 1)) s = 1;
            if(s2 == 0 ) s2 = n;
        }
        ans += mul;
        ans -= mul2;
    }
    return ans;
}


void transpose(vector<vector<double>> &M)
{
    int n = M.size();
    vector<vector<double>> temp(n, vector<double>(n, 0));
    for( int i = 1 ; i < n; i++)
    {
        for( int j = 1 ; j < n; j++)
        {
            temp[i][j] = M[j][i];
        }
    }
    for( int i = 1 ; i < n; i++)
    {
        for( int j = 1 ; j < n; j++)
        {
            M[i][j] = temp[i][j];
        }
    }
}

void div(vector<vector<double>> &M, double x)
{
    int n = M.size();
    for( int i = 1 ; i < n; i++)
    {
        for( int j = 1 ; j < n; j++)
        {
            M[i][j]/= x;
        }
    }
}
int main()
{
    int n;;
    cout<<"Enter number of unkown:";
    cin>>n;
    vector<vector<double>>A(n+ 1,vector<double>(n + 1,0)),invA(n+ 1,vector<double>(n + 1,0));

    vector<double>B(n + 1);
    for( int i = 1 ; i <= n; i++)
    {
        for( int j = 1 ; j <= n; j++)
        {
            cout<<"Enter a"<<i<<j<<" : ";
            cin>>A[i][j];
        }
        cout<<"Enter b"<<i<<": ";
        cin>>B[i];
    }

    double detA = det(A);
    if(fabs(detA - 0.0) < 0.000001 )
    {
        cout<<"Invalid\n";
        return 0;
    }

    for( int r = 1 ; r <= n; r++)
    {
        for( int c = 1 ; c<= n; c++)
        {
            vector<vector<double>>t;
            vector<double>temp;
            t.push_back(temp);///1 based indexing by pushing a intial value
            for( int rr = 1 ; rr <= n; rr++)
            {
                temp.clear();
                temp.push_back(0);
                for( int cc = 1 ; cc<= n; cc++)
                {
                    if(rr != r and cc != c)
                    {
                        temp.push_back(A[rr][cc]);
                    }
                }
                if(temp.size() > 1)
                    t.push_back(temp);
            }
            double tt = pow(-1,r + c) * det(t);
            invA[r][c] = tt;
        }
    }
    ///transpose
    transpose(invA);
    div(invA,detA);
    for( int i = 1 ; i <= n ; i++)
    {
        for( int j = 1 ; j <=n ; j++)
        {
            cout<<invA[i][j]<<' ';
        }
        cout<<endl;
    }

  vector<double>answer;
    for( int r = 1; r <= n; r++)
    {
        double t =0;
        for( int c = 1; c <= n; c++)
        {
            t += B[c] * invA[r][c];
        }
        answer.push_back(t);
    }
    for( int i = 1 ; i <= n;i++)
    {
        cout<<"x"<<i<<" = "<<answer[i-1]<<endl;
    }
}

/*
Input:
3
3 1 2 3
2 -3 -1 -3
1 2 1 4
Output:
x1 = 1
x2 = 2
x3 = -1
Input:
3
1 1 1 1
1 2 3 6
1 3 4 6
Output:
x1 = 1
x2 = -5
x3 = 5
*/

