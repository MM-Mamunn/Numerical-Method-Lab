///You are given a number (eg: 2.995) and a point that indicates the digit after decimal point. Round to that point

#include<bits/stdc++.h>

using namespace std;

void print_final(string si, string sf, int p)
{
    ///remove leading zeros
    while(sf.size() > p)
        sf.pop_back();

    while(!si.empty() and si[0] == '0')
        si.erase(si.begin());
    if(sf.empty())sf = "0";
    cout<<si<<'.'<<sf<<endl;
}
int cal()
{
    int i, f = 0, p;
    char ch;
    cout<<"Enter the point: ";
    cin>>p;
    cout<<"Enter the number (x.y type): ";
    string sf ="",si="",s;
    cin>>s;
    for(auto a : s)
    {
        if(a == '.')
        {
            f = 1;
            continue;
        }
        if(f)
            sf+=a;
        else
            si += a;
    }

    if(sf.size() <= p)
    {
        cout<<si<<'.'<<sf<<endl;
        return 0;
    }
///Adding a leading '0' for easier calculation
    si= '0' + si;

    int t= sf[p] - '0';

///flag to control how far the rounding should traverse
    int fl = 0;

    if(t < 5 or t == 5 and (sf[p - 1]- '0') % 2 == 0)
    {
        print_final(si,sf,p);
        return 0;
    }
    if(t == 5 and (sf[p - 1]- '0') % 2 or t > 5)
    {
        int ptr = p - 1;
        while(ptr >= 0)
        {
            if(sf[ptr] == '9')
            {
                sf[ptr] = '0';
                --ptr;
                fl = 1;
                continue;
            }
            else
            {
                sf[ptr] += 1;
                fl = 0;
                break;
            }
        }
//    ///when rounding comes to integer part
        if(fl)
        {
            int ptr = si.size() - 1;
            while(si[ptr] == '9')
                {
                    si[ptr] = '0';
                    --ptr;
                }
            ++si[ptr];
        }
        print_final(si,sf,p);
    }
}
int32_t main()
{
    int t;
    cout<<"Enter the number of test case:";
    cin>>t;
    while(t--)
    {
        cal();
    }
}

/*
TC:
6
2
2.995
2
2.985
2
2.987
2
2.997
2
2.983
2
2.993
*/
