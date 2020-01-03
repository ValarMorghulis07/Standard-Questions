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
  ll n;
  cin>>n;
  ll a[n];
  f(n)
   cin>>a[i];
  ll pre[n];
  map<ll,ll>mp;
  pre[0]=a[0];
  mp[a[0]]++;
  for(ll i=1;i<n;i++)
  {
   pre[i]=pre[i-1]+a[i];
   mp[pre[i]]++;
  }
  ll cnt=0;
  for(auto itr=mp.begin();itr!=mp.end();++itr)
  {
    if(itr->first==0)
    {
     cnt+=itr->second;
     ll zz=itr->second;
     cnt+=(zz*(zz-1)/2);
    }
    else if(itr->second>1)
    {
     ll zz=itr->second;
     cnt+=(zz*(zz-1)/2);
    }
  }
  cout<<cnt<<endl;
  /*for(ll i=0;i<n;i++)
  {
   if(pre[i]==0 && mp[0]>=0)
   {
    cnt+=mp[pre[i]];
    ll zz=mp[pre[i]];
    cnt+=(zz*(zz-1)/2);
    mp[pre[i]]=-1;
   }
   else if(mp[pre[i]]>1)
   {
    ll zz=mp[pre[i]];
    cnt+=(zz*(zz-1)/2);
    mp[pre[i]]=-1;
   }

  }
  cout<<cnt<<endl;*/

 }
 return 0;
}
