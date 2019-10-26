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

bool rr;
void print(vector<ll>q)
{
  ll zz=q.size();
  cout<<"(";
  f(zz-1)
   cout<<q[i]<<" ";
  cout<<q[zz-1]<<")";
}

void combisum(vector<ll>v,vector<ll>q,ll target,ll pp,ll sum)
{
 if(sum==target)
 {
  rr=true;
  print(q);
  return;
 }
 for(ll i=pp;i<v.size();i++)
 {
  if(sum>target)
     return;
  q.pb(v[i]);
  combisum(v,q,target,pp,sum+v[i]);
  pp++;
  if(q.size()==0)
   return;
  q.pop_back();
 }
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  set<ll>s;
  ll a[n];
  f(n)
  {
   cin>>a[i];
   s.insert(a[i]);
  }
  ll target;
  cin>>target;
  vector<ll>v,q;
  ll zz=s.size();
  set<ll>::iterator itr;
  for(itr=s.begin();itr!=s.end();++itr)
    v.pb(*itr);
  rr=false;
  combisum(v,q,target,0,0);
  if(!rr)
     cout<<"Empty"<<endl;
  cout<<"\n";
 }
 return 0;
}
