/*
Write a program to solve the following system of linear equations by using Cramer’s Rule:
           27x +   6y – z     =  85
           6x + 15y + 2z   = 72
           x +     y + 54z = 110
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
    double detA = determinant(A,n);
    if(fabs(detA - 0.0) < 0.000001 )
    {
        cout<<"Invalid\n";
        return 0;
    }
    vector<vector<double>>temp;
    vector<double>answer;
    for( int i = 1; i <= n;i++)
    {
        temp = A;
        for(int j = 1; j <= n ;j++)
        {
            temp[j][i] = B[j];
        }
        answer.push_back((determinant(temp,temp.size() - 1) )/ detA );
    }
    for( int i = 0 ; i < answer.size(); i++)
    {
        cout<<"x"<<i+1<<" = "<<answer[i]<<endl;
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
Input:
3
27 6 -1 85
6 15 2 72
1 1 54 110
Output:
x1 = 2.42548
x2 = 3.57302
x3 = 1.92595
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
