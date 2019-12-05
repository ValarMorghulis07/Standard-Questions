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
  ll n1,n2,k;
  cin>>n1>>n2>>k;
  ll a[n1],b[n2];
  map<ll,ll>mp;
  f(n1)
  {
   cin>>a[i];
  }
  f(n2)
  {
    cin>>b[i];
    mp[b[i]]++;
  }
  ll ff=0;
  vector<pair<ll,ll>>vec;
  f(n1)
  {
   if(mp[k-a[i]]>0)
   {
    ff=1;
    vec.pb(m_p(a[i],k-a[i]));
   }
  }
  sort(vec.begin(),vec.end());
 if(ff==1)
 {
    ll zz=vec.size();
    f(zz)
    {
    cout<<vec[i].first<<" "<<vec[i].second;
    if(i!=zz-1)
      cout<<","<<" ";
    }
 }
  if(ff==0)
    cout<<"-1";
  cout<<"\n";
 }
 return 0;
}
