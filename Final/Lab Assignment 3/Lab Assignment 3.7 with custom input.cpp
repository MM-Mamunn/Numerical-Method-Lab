/*
Write a program to solve the following system of linear equations by using Matrix inversion method.
          x +  y  +   z = 1
          x + 2y + 3z = 6
          x + 3y + 4z = 6
*/


#include<bits/stdc++.h>

using namespace std;


// Function to get the minor matrix by excluding row `p` and column `q`
void getMinor(const vector<vector<double>> &mat, vector<vector<double>> &minor, int n, int p, int q) {
    int i = 1, j = 1;
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n; col++) {
            if (row != p && col != q) {
                minor[i][j++] = mat[row][col];
                if (j > n - 1) {
                    j = 1;
                    i++;
                }
            }
        }
    }
}

// Recursive function to calculate determinant
double determinant(const vector<vector<double>> &mat, int n) {
    if (n == 1)
        return mat[1][1];

    if (n == 2)
        return mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];

    double det = 0;
    vector<vector<double>> minor(n, vector<double>(n));

    int sign = 1; // Sign for cofactor

    for (int f = 1; f <= n; f++) {
        getMinor(mat, minor, n, 1, f);
        det += sign * mat[1][f] * determinant(minor, n - 1);
        sign = -sign;
    }

    return det;
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

    double detA = determinant(A, n);
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
            double tt = pow(-1,r + c) * determinant(t,t.size() - 1);
            invA[r][c] = tt;
        }
    }
    ///transpose
    transpose(invA);
    div(invA,detA);
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
5
1 1 1 1 1 15
2 1 1 1 1 16
1 2 1 1 1 17
1 1 2 1 1 18
1 1 1 2 1 19
Output:
x1 = 1
x2 = 2
x3 = 3
x4 = 4
x5 = 5
*/
