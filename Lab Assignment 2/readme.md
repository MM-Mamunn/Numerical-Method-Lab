///Bismillah - Segment Tree
///Update and query O(log(n)), Build N \* 4
#include <bits/stdc++.h>
using namespace std;

const long long N2 = 2e5 + 12;
long long a[N];
long long t2[N * 4];

///means in node "node" there is a range begins with array index "b" and ends with array index "e"
void build2(long long node, long long b, long long e)
{
if(b == e)///segment with one element base case
{
t2[node] = a[b];
return;
}
long long l = 2 _ node, r = 2 _ node + 1;///childs of parent "node" are l ,r
long long mid = ( b + e) / 2;
///building two child
build2(l,b, mid);
build2(r, mid + 1, e);
///now the child of node "node" is build , and the sum of node = sum of child,
t2[node] = max(t2[l] , t2[r]);
}

///need sum of range (i - j) currently in node "node" that contains the sum of range (b - e)
long long query2(long long node,long long b,long long e, long long i, long long j )
{
if( b > j or e <i) return 0;///not in the range
if(b >=i and e <= j)///means this need is fully in the given range
return t2[node];
///current range long longersects i- j,so go to the left right child
long long l = 2 _ node, r = 2 _ node + 1;///childs of parent "node" are l ,r
long long mid = ( b + e) / 2;
return max(query2(l, b,mid,i, j) , query2(r, mid + 1,e, i,j));
}

const long long N = 2e5 + 12;
//long long a[N];
long long t[N * 4];

///means in node "node" there is a range begins with array index "b" and ends with array index "e"
void build(long long node, long long b, long long e, long long k)
{
if(b == e)///segment with one element base case
{
t[node] = a[b];
return;
}
long long l = 2 _ node, r = 2 _ node + 1;///childs of parent "node" are l ,r
long long mid = ( b + e) / 2;
///building two child
build(l,b, mid,k);
build(r, mid + 1, e,k);
///now the child of node "node" is build , and the sum of node = sum of child,
// t[node] = max(t[l] , t[r]);
for( long long i = l ; i <= r;i++)
{
long long need = max(0, k - a[i]);
for( long long j = 31;j>=0;j++)
{

        }
    }

}

///need sum of range (i - j) currently in node "node" that contains the sum of range (b - e)
long long query(long long node,long long b,long long e, long long i, long long j )
{
if( b > j or e <i) return 0;///not in the range
if(b >=i and e <= j)///means this need is fully in the given range
return t[node];
///current range long longersects i- j,so go to the left right child
long long l = 2 _ node, r = 2 _ node + 1;///childs of parent "node" are l ,r
long long mid = ( b + e) / 2;
return query(l, b,mid,i, j) | query(r, mid + 1,e, i,j);
}

long long main()
{
long long n,k;
cin>>n>>k;
for( long long i = 1; i <= n; i++)
cin>>a[i];

    build2(1, 1, n,k);
    build(1, 1, n,k);
    cout<<query(1,1,n,3,4)<<endl;

    long long ans = -1, l = 1,r = n;
    while(l <= r)
    {
        long long mid = (l + r)/2;
        long long ll = 1 , rr = mid;
        long long mn = n + 2;
        mn = query(1,1,n,ll,rr);
        while(rr <= n)
        {
            ++rr;
            ++ll;
            mn = min(mn,query(1,1,n,ll,rr));
        }
        if(mn >= k)
        {
            ans = mid;
            r = mid -1 ;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout<<ans<<'\n';

}
