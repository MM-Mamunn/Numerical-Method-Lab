///Find a root of non linear equation using bisection technique

#include<bits/stdc++.h>
using namespace std;

double eps = 0.005;

bool cal(double mid)
{
    double ans = (mid* mid* mid) - mid-1;
    if(ans  < 0.0 )
        return true;
    return false;
}
int main()
{
    double largest = 2.0;
    double  smallest = 1.0;
    int c = 0;
    while(true)
    {
        double diff = fabs(largest - smallest);
        if(diff <= eps)
            break;

        double mid = (largest + smallest) / 2.00;
        if(cal(mid))
            smallest = mid;
        else largest = mid;
    }
    cout<<fixed<<setprecision(9)<<smallest<<endl;

}
