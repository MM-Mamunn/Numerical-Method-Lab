
///find the number of significant digit

#include<bits/stdc++.h>

using namespace std;

int cal()
{
    int i, f = 0, p;
    char ch;
    string sf="", si="",s ;
    cout<<"Enter the number (x.y type): ";
    cin>>s;
    for(auto a : s)
    {
        if(a == '.')
        {
            f = 1;
            continue;
        }
        if(!f)
            si += a;
        else
            sf += a;

    }
    if(!f)
    {
        while(!si.empty() and si.back() == '0')
            si.pop_back();
        cout<<"Number of Significant digits is "<<si.size() + sf.size()<<endl;
        return 0;
    }

    while(!si.empty() and si[0] == '0')
        si.erase(si.begin());
    if(si.empty())
        while(!sf.empty() and sf[0]== '0')
            sf.erase(sf.begin());
    cout<<"Number of Significant digits is "<<si.size() + sf.size()<<endl;


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
4
45.003
00.0033
00330.003300
1200
*/
