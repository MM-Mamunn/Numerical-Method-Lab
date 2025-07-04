/*
Write a program to solve the following system of linear equations by using Cramer’s Rule:
           27x +   6y – z     =  85
           6x + 15y + 2z   = 72
           x +     y + 54z = 110
*/

#include<bits/stdc++.h>

using namespace std;

double det(vector<vector<double>> &A)
{
    return (A[1][1] * A[2][2] * A[3][3]) +
                  (A[1][2] * A[2][3] * A[3][1]) +
                  (A[1][3] * A[2][1] * A[3][2]) -
                  (A[1][1] * A[2][3] * A[3][2]) -
                  (A[1][2] * A[2][1] * A[3][3]) -
                  (A[1][3] * A[2][2] * A[3][1]) ;;
}

int main()
{

vector<vector<double>>A(4, vector<double>(4, 0));
vector<double>B(4),answer;
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

    double detA = det(A);
    if(fabs(detA - 0.0) < 0.000001 )
    {
        cout<<"Invalid\n";
        return 0;
    }
    vector<vector<double>>temp;

    for( int i = 1; i <= 3;i++)
    {
        temp = A;
        for(int j = 1; j <= 3 ;j++)
        {
            temp[j][i] = B[j];
        }
        answer.push_back((det(temp) )/ detA );
    }
    for( int i = 0 ; i < answer.size(); i++)
    {
        cout<<"x"<<i+1<<" = "<<answer[i]<<endl;
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
Input:
27 6 -1 85
6 15 2 72
1 1 54 110
Output:
 x1 = 2.42548
x2 = 3.57302
x3 = 1.92595
*/
