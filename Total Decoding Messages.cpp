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

void solve(string str,ll n)
{
 ll dp[n+1];
 dp[0]=1,dp[1]=1;
 if(str[0]=='0')
 {
  cout<<"0"<<endl;
  return;
 }
 for(ll i=2;i<=n;i++)
 {
  dp[i]=0;
  if(str[i-1]>'0')
    dp[i]=dp[i-1];
  if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<'7'))
     dp[i]+=dp[i-2];
 }
 cout<<dp[n]<<endl;
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
  string str;
  cin>>str;
  solve(str,n);
 }
 return 0;

}
