///ID: C221046
///UVA 498

#include<bits/stdc++.h>

using namespace std;
#define ll long long


int main()
{

   string str1,str2;
   while(getline(cin,str1))
   {
       stringstream ss(str1);
       vector<ll> c,x;
       ll t;
       while(ss >> t)
        c.push_back(t);

       getline(cin,str2);
       stringstream ss2(str2);
        while(ss2 >> t)
        x.push_back(t);
        int i = 0;
        for(auto xx : x)
        {
            int n = c.size() - 1;
            ll sum =0;
            for(auto cc : c)
            {
                sum+= (cc * pow(xx,n--));
            }
            if(i)
                cout<<' ';
            cout<<sum;
            ++i;
        }
        cout<<endl;
   }
    return 0;
}




///UVA 10341

#include<bits/stdc++.h>

using namespace std;

int p,q,r,s,t,u;

double cal(double x)
{
    return ((double)p *  exp(-x) ) + ((double)q  * sin(x) ) + ((double)r *cos(x)) + ((double)s * tan(x)) + ((double)t *x*x) + (double)u ;
}

int main()
{

    while(cin>>p>>q>>r>>s>>t>>u)
    {
        double l = 0.0, r = 1.0;
        if((cal(l) * cal(r) )> 0.0)
        {
            cout<<"No solution\n";
            continue;
        }
        int c = 0;
        while(c++ <= 100)
        {
            double mid = (l + r)/ 2.0;
            if(cal(mid) > 0.0)
                l = mid;
            else
                r = mid;
        }
        cout<<fixed<<setprecision(4)<<r<<endl;
    }
    return 0;
}




