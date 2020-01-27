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
  vector<ll>vec;
  map<ll,bool>mp;
  vec.pb(1);
  vec.pb(2);
  vec.pb(3);
  mp[1]=1,mp[2]=1,mp[3]=1;
  ll num=1,num2;
  ll j=0;
  while(num<1000001)
  {
   num2=vec[j++];
   if(num2*10+1<1000001)
   {
    vec.pb(num2*10+1);
    mp[num2*10+1]=1;
   }
   if(num2*10+2<1000001)
   {
    vec.pb(num2*10+2);
    mp[num2*10+2]=1;
   }
   if(num2*10+3<1000001)
   {
    vec.pb(num2*10+3);
    mp[num2*10+3]=1;
   }
   num=num2*10+3;
  }
  ll ff=0;
  vector<ll>ans;
  for(ll i=0;i<n;i++)
  {
   if(mp[a[i]])
    ans.pb(a[i]);
  }
  if(ans.size()==0)
    cout<<"-1";
  else
  {
    sort(ans.begin(),ans.end());
    f(ans.size())
     cout<<ans[i]<<" ";

  }
  cout<<"\n";
 }

 return 0;

}
