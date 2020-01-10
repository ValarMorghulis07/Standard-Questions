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
  ll start[n],finish[n];
  vector<pair<ll,pair<ll,ll>>>vec;
  f(n)
   cin>>start[i];
  f(n)
   cin>>finish[i];
  f(n)
   vec.pb(m_p(finish[i],m_p(start[i],i+1)));
  sort(vec.begin(),vec.end());

  ll check=vec[0].first,index=0;
  cout<<vec[0].second.second<<" ";

  for(ll i=1;i<n;i++)
  {
    if(vec[i].second.first>=check)
    {
     cout<<vec[i].second.second<<" ";
     check=vec[i].first;
    }
  }
  cout<<"\n";


 }
 return 0;

}
