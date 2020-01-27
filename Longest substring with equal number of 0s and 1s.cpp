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
  string str;
  cin>>str;
  ll n=str.length();
  map<ll,ll>mp;
  ll maxx=0,sum=0;
  for(ll i=0;i<n;i++)
  {
   if(str[i]=='1')
     sum++;
   else
     sum--;
   if(sum==0)
    maxx=max(maxx,i+1);
   else if(mp.find(sum)!=mp.end())
    maxx=max(maxx,i-mp[sum]);
   else
    mp[sum]=i;
  }
  cout<<maxx<<endl;

 }
 return 0;

}
