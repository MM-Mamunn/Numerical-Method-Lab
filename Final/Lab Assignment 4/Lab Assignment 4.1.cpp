/*
Write a program to find the least square line y = a + bx for the following data
        x     -2    -1     0     1     2
*/

#include<bits/stdc++.h>

using namespace std;


int main()
{

    int n,i =0;
    cout<<"Enter number of entries: ";
    cin>>n;
    vector<double>x(n),y(n);
    double sx = 0, sy= 0, sxs = 0,sxy=0;
    cout<<"Enter "<<n<<" entries of x:\n";
    for(auto &a : x)
    {
        cin>>a;
        sx +=a;
        sxs += (a*a);
    }
    cout<<"Enter "<<n<<" entries of y:\n";
    for(auto &a : y)
    {
        cin>>a;
        sy += a;
        sxy += (x[i++] * a);
    }
    double a = (1.00 * sy * sxs) - (1.00 * sx * sxy);
    a /= (1.00 * n * sxs) - (1.00 * (sx)*(sx));
    double b = (1.00 * n * sxy) - (1.00 * sx * sy);
    b/= (1.00 * n * sxs) - (1.00 * (sx)*(sx));
     cout <<"The line equation is : y = "<<a<<((b >= 0.0) ? "+" : "-") << abs(b) << "x" << endl;


}

/*
Input:
5
-2 -1 0 1 2
1 2 3 4 5
Output:
The line equation is : y = 3+1x
Input:
4
0 2 5 7
-1 5 12 20
Output:
The line equation is : y = -1.13793+2.89655x
*/
