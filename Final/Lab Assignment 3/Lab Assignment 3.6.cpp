///Write a program to find the determinant of a 3X3 matrix.
#include<bits/stdc++.h>

using namespace std;

int32_t main()
{
    int mat[4][4];
    for( int i = 1 ; i <= 3; i++)
    {
        for( int j = 1 ; j <= 3;j++)
        {
            cout<<"enter mattrix["<<i<<"]["<<j<<"] :";
            cin>>mat[i][j];
        }
    }
    int det = 0;
    det = mat[1][1] * (( mat[2][2] * mat[3][3] ) - (mat[2][3] * mat[3][2]));
    det -= mat[1][2] * (( mat[2][1] * mat[3][3] ) - (mat[2][3] * mat[3][1]));
    det += mat[1][3] * (( mat[2][1] * mat[3][2] ) - (mat[2][2] * mat[3][1]));

    cout<<"|matrix| = "<<det<<endl;

    return 0;
}
