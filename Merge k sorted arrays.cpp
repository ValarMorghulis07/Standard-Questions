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

const ll N=1e3+5;
ll a[N][N];
ll k,n;

void MergeSortedArray()
{
 vector<ll>ans;
 priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
 for(ll i=0;i<k;i++)
    pq.push(m_p(a[i][0],m_p(i,0)));
 while(!pq.empty())
 {
  ll u=pq.top().first;
  ll v=pq.top().second.first;
  ll w=pq.top().second.second;
  pq.pop();
  ans.pb(u);
  if(w+1<n)
    pq.push(m_p(a[v][w+1],m_p(v,w+1)));
 }
 f(ans.size())
  cout<<ans[i]<<" ";
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>k>>n;
  f(k)
  {
   r(n)
   {
    cin>>a[i][j];
   }
  }
  MergeSortedArray();
  cout<<"\n";
 }
 return 0;
}