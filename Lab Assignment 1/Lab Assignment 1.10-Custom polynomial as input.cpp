///Write a program to find all the roots of the equation x3 - 6x + 4 = 0, correct to 3 decimal places. [Use Newton-Raphson method with deflation].

#include <bits/stdc++.h>
using namespace std;

//Find f(x)
double f(double x, vector<double>c)
{
     int n = c.size();
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += 1.00 * (c[i] * pow(x, i));
    }
    return result;
}

//Find f'(x)
double fprime(double x, vector<double>c)
{
     int n = c.size();
    double result = 0.0;
    for (int i = 1; i < n; ++i) { // Start from 1 since the derivative of x^0 is 0
        result += 1.00 *(i * c[i] * pow(x, i - 1));
    }
    return result;

}

int main()
{
    int n;
    cout<<"Enter the degree of the polynomial :";
    cin>>n;
    vector<double>c(n + 1);
    for( int i = n; i>=0; i--)
    {
        cout<<"Enter the coefficient of x^"<<i<<" :";
        cin>>c[i];
    }
    vector<double>roots;
    double x =1.0;
    while(n > 1)
    {
        ///evaluate Newton-Raphson
        double xNew = x - f(x,c) / fprime(x,c);

        while(fabs(xNew- x) > (0.0001))
        {
            x = xNew;

            xNew = x - f(x,c) / fprime(x,c);
        }

        roots.push_back(xNew);
        x = xNew;
        ///Synthetic division starts(same as finding quotient polynomial)
        vector<double>temp(n + 1 );
        temp[n] = 0;
        for(int i = n - 1 ; i >= 0; i--)
            temp[i] = (c[i + 1] + x * temp[i  + 1]);

        ///Synthetic division ends

        c.clear();

        temp.pop_back();
        c = temp;
        --n;
    }
    int i = 1;
    roots.push_back(-c[0]/c[1]);
    for(auto a : roots)
        cout<<"Root "<<i++<<": "<<a<<endl;
}
/*
Input:
3
1
0
-6
4
Output:
Root 1: 0.732051
Root 2: 2
Root 3: -2.73205
*/
