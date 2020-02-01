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

vector<ll>adj[20];
vector<ll>ans;


void DoIt()
{
 priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
 pq.push(m_p(adj[0][0],m_p(0,0)));
 pq.push(m_p(adj[1][0],m_p(1,0)));
 while(!pq.empty())
 {
  ll u=pq.top().first;
  ll v=pq.top().second.first;
  ll w=pq.top().second.second;
  pq.pop();
  ans.pb(u);
  if(w+1<adj[v].size())
    pq.push(m_p(adj[v][w+1],m_p(v,w+1)));
 }

 f(ans.size())
  cout<<ans[i]<<" ";
 cout<<"\n";

}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll m,n;
  cin>>m>>n;
  f(m)
  {
   ll x;
   cin>>x;
   adj[0].pb(x);
  }
  f(n)
  {
   ll x;
   cin>>x;
   adj[1].pb(x);
  }
  DoIt();
  adj[0].clear();
  adj[1].clear();
  ans.clear();
 }
 return 0;
}
