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
  ll k;
  cin>>k;
  vector<ll>vec;
  vector<ll>::iterator itr;
  ll cnt=0,j=0;
  for(ll i=0;i<n;i++)
  {
   if(find(vec.begin(),vec.end(),a[i])!=vec.end())
   {
    itr=find(vec.begin(),vec.end(),a[i]);
    vec.erase(itr);
    vec.pb(a[i]);
   }
   else if(j<k)
   {
    vec.pb(a[i]);
    cnt++;
    j++;
   }
   else
   {
    vec.erase(vec.begin());
    vec.pb(a[i]);
    cnt++;
   }
  }
  cout<<cnt<<endl;
 }
 return 0;

}
