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

/*void solve1(ll a[],ll n)
{
 cout<<"1"<<" ";
 for(ll i=1;i<n;i++)
 {
  ll cnt=1;
  for(ll j=i-1;j>=0;j--)
  {
   if(a[i]>=a[j])
    cnt++;
   else
    break;
  }
  cout<<cnt<<" ";
 }
 cout<<"\n";
}*/
void solve2(ll a[],ll n)
{
 stack<ll>stk;
 ll ans[n];
 ans[0]=1;
 stk.push(0);
 for(ll i=1;i<n;i++)
 {
  while(!stk.empty() && a[i]>=a[stk.top()])
    stk.pop();
  ans[i]=(stk.empty()) ? (i+1):(i-stk.top());
  stk.push(i);
 }
 f(n)
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
  ll n;
  cin>>n;
  ll a[n];
  f(n)
   cin>>a[i];
  //solve1(a,n)[o(n*n)];
  solve2(a,n);
 }
 return 0;
}
