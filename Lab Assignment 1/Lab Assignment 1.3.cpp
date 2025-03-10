/// Write a program to evaluate a polynomial f(x) = x3 - 2x2 + 5x + 10  by using Horner's rule x = 5.

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{

    string str1, str2;
    while (getline(cin, str1))
    {
        stringstream ss(str1);
        vector<ll> c, x;
        ll t;
        while (ss >> t)
            c.push_back(t);

        getline(cin, str2);
        stringstream ss2(str2);
        while (ss2 >> t)
            x.push_back(t);
        int i = 0;
        for (auto xx : x)
        {
            int n = c.size() - 1;
            ll sum = 0, p = c[0];
            for (int j = 1; j < c.size(); j++)
            {
                p = (p * xx) + c[j];
            }
            if (i)
                cout << ' ';
            cout << p;
            ++i;
        }
        cout << endl;
    }
    return 0;
}
