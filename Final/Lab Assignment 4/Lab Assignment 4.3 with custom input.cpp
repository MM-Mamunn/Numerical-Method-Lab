/*
Write a program to find the best possible values of a and b from the relation y = aebx for the following data:
    x	2	10	26	61
    y	600	500	400	350

*/
/*
ln(y) = ln(a) + bx
Y = A0 + A1X.
calculate A1 same as 'b' in a line equation.
A0 = avg(Y) - A1 avg(X)
a = exp(A0)
*/
#include <bits/stdc++.h>

using namespace std;


int main()
{
int n;
cout<<"Enter number of entries: ";
cin>>n;
double sx = 0, sy = 0, sxs = 0,sxy = 0;
vector<double> x(n + 1), y (n + 1);
cout<<"Enter the "<<n<<" entries of x:";
for( int i = 1; i <= n;i++)
{
    cin>>x[i];
    sx += x[i];
    sxs += (x[i] * x[i]);
}

cout<<"Enter the "<<n<<" entries of y:";
for( int i = 1; i <= n;i++)
{
    cin>>y[i];
    y[i] = log(y[i]);
    sy += y[i];
    sxy += x[i] * y[i];
}
double A1 = (n * (sxy)) - (sx * sy);
A1 /= (1.00 * n * sxs) - (1.00 * sx * sx);
sx /= (1.00 * n);
sy /= (1.00 * n);
double A0 = sy - (A1* sx);
A0 = exp(A0);
cout<<"y = "<<A0<<"e^"<<A1<<"x\n";
}

/*
Input:
5
1 3 5 7 9
2.473 6.722 18.274 49.673 135.026
Output:
y = 1.49992e^0.500007x
Input:
4
2 10 26 61
600 500 400 350
Output:
y = 558.191e^-0.00846335x
*/
