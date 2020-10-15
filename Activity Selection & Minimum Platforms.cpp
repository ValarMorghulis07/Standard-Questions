// Activity Selection

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/


int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  ll arr[n],dep[n];
  rep(i,0,n)
  {
   cin>>arr[i];
  }
  rep(i,0,n)
  {
    cin>>dep[i];
  }
  vector<pair<ll,ll>>vec;
  rep(i,0,n)
  {
   vec.pb(m_p(dep[i],arr[i]));
  }
  sort(vec.begin(),vec.end());
  ll cnt=1;
  ll depar=vec[0].first;
  for(ll i=1;i<n;i++)
  {
    if(vec[i].second>=depar)
    {
     cnt++;
     depar=vec[i].first;
    }
  }
  cout<<cnt<<endl;
 }
 return 0;
}

// 452. Minimum Number of Arrows to Burst Balloons--> Same as Activity Selection with little difference in if condition.

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
      int n=points.size();
      if(n<2)
          return n;
      vector<pair<int,int>>vv;
      for(int i=0;i<n;i++)
           vv.push_back({points[i][1],points[i][0]});
     sort(vv.begin(),vv.end());
      int x2=vv[0].first;
      int idx=1;
      int cnt=1;
      while(idx<n)
      {
       if(vv[idx].second>x2)
       {
        cnt++;
        x2=vv[idx].first;
       }
       idx++;
      }
      return cnt;
    }
};

// Minimum Platforms

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
