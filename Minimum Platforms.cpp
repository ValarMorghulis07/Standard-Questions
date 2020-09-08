#include<bits/stdc++.h>
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
  ll arr[n],dep[n];
  f(n)
   cin>>arr[i];
  f(n)
   cin>>dep[i];
  vector<pair<ll,ll>>vec;
  f(n)
   vec.pb(m_p(arr[i],dep[i]));
  
  sort(vec.begin(),vec.end());
  ll zz=vec[0].second;
   priority_queue<ll,vector<ll>,greater<ll>>pq;
   pq.push(zz);
   ll maxx=0;
   for(ll i=1;i<n;i++)
   {
     if(vec[i].first>pq.top())
     {
      pq.pop();
      pq.push(vec[i].second);
     }
     else
       pq.push(vec[i].second);
     ll pp=pq.size();
     maxx=max(maxx,pp);
   }
   cout<<maxx<<endl;
  

 }
 return 0;
}
