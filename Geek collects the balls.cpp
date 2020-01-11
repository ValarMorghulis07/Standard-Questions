#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll m,n;
  cin>>m>>n;
  ll a[m],b[n];
  ll pre1[m+1],pre2[n+1];
  f(m)
   cin>>a[i];
  f(n)
   cin>>b[i];
  pre1[0]=a[0],pre2[0]=b[0];
  set<ll>common;
  for(ll i=0;i<m;i++)
  {
   if(binary_search(b,b+n,a[i]))
    common.insert(a[i]);
  }
  for(ll i=1;i<m;i++)
    pre1[i]=pre1[i-1]+a[i];
  for(ll i=1;i<n;i++)
    pre2[i]=pre2[i-1]+b[i];
  ll sum=0,xx=m,yy=n;
  pre1[xx]=0,pre2[yy]=0;
  ll upper1,upper2;
   for(auto itr=common.begin();itr!=common.end();++itr)
   {
     upper1=upper_bound(a,a+m,*itr)-a;
     upper2=upper_bound(b,b+n,*itr)-b;
     sum+=max(pre1[upper1-1]-pre1[xx],pre2[upper2-1]-pre2[yy]);
     xx=upper1-1;
     yy=upper2-1;



   }
   sum+=max(pre1[m-1]-pre1[xx],pre2[n-1]-pre2[yy]);
   cout<<sum<<endl;


 }
 return 0;
}
