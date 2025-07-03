/*
Write a program to solve the following system of linear equations by using Matrix inversion method.
          x +  y  +   z = 1
          x + 2y + 3z = 6          
          x + 3y + 4z = 6 
*/


#include<bits/stdc++.h>

using namespace std;

double A[4][4],B[4],invA[4][4], tA[4][4];

int main()
{

    for( int i = 1 ; i <= 3; i++)
    {
        for( int j = 1 ; j <= 3; j++)
        {
            cout<<"Enter a"<<i<<j<<" : ";
            cin>>A[i][j];
        }
        cout<<"Enter b"<<i<<": ";
        cin>>B[i];
    }

    double detA = (A[1][1] * A[2][2] * A[3][3]) +
                  (A[1][2] * A[2][3] * A[3][1]) +
                  (A[1][3] * A[2][1] * A[3][2]) -
                  (A[1][1] * A[2][3] * A[3][2]) -
                  (A[1][2] * A[2][1] * A[3][3]) -
                  (A[1][3] * A[2][2] * A[3][1]) ;
    if(fabs(detA - 0.0) < 0.000001 )
    {
        cout<<"Invalid\n";
        return 0;
    }
    for( int r = 1; r <= 3; r++)
    {
        for( int c = 1; c <= 3; c++)
        {
            ///Calculate the determinant
            vector<double>temp;
            for( int rr = 1; rr <= 3; rr++)
            {
                for( int cc = 1; cc <= 3; cc++)
                {
                    if(rr != r and cc != c)
                        temp.push_back(A[rr][cc]);
                }
            }
            double t = pow(-1, r + c) *( (temp[0] * temp[3]) - (temp[1] * temp[2]));
            invA[r][c] = t;
        }

    }
    ///transpose
    for( int r = 1; r <= 3; r++)
    {
        for( int c = 1; c <= 3; c++)
        {
            tA[c][r] = invA[r][c];
        }
    }
    ///copy to the orginal
    for( int r = 1; r <= 3; r++)
    {
        for( int c = 1; c <= 3; c++)
        {
            invA[r][c] = (tA[r][c])/ detA;
        }
    }


  vector<double>answer;
    for( int r = 1; r <= 3; r++)
    {
        double t =0;
        for( int c = 1; c <= 3; c++)
        {
            t += B[c] * invA[r][c];
        }
        answer.push_back(t);
    }
    for( int i = 1 ; i <= 3;i++)
    {
        cout<<"x"<<i<<" = "<<answer[i-1]<<endl;
    }
}

/*
Input:
3 1 2 3
2 -3 -1 -3
1 2 1 4
Output:
x1 = 1
x2 = 2
x3 = -1
Input:
1 1 1 1 
1 2 3 6
1 3 4 6
Output:
x1 = 1
x2 = -5
x3 = 5
*/

