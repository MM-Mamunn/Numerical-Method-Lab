#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    ll k;
    string s;
    while (cin >> k)
    {
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);
        vector<ll> c;
        ll t;
        while (ss >> t)
        {
            c.push_back(t);
        }

        reverse(c.begin(), c.end());
        int n = c.size() - 1;

        vector<ll> q(n + 1);
        q[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            q[i] = c[i + 1] + k * q[i + 1];
        }
        cout << "q(x):";
        for (int i = n - 1; i >= 0; i--)
        {
            cout << ' ' << q[i];
        }
        cout << '\n';
        ll r = c[0] + k * q[0];
        cout << "r = " << r << "\n\n";
    }
}
