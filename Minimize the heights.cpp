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

ll solve(ll a[],ll n,ll k)
{
 if(n==1)
    return 0;
 ll ans=a[n-1]-a[0];
 ll small=a[0]+k;
 ll big=a[n-1]-k;
 if(small>big)
    swap(small,big);
 for(ll i=1;i<n-1;i++)
 {
  ll add=a[i]+k;
  ll subtract=a[i]-k;
  if(subtract>=small || add<=big)
    continue;
  if(big-subtract>add-small)
    big=add;
  else
    small=subtract;
 }
 return min(ans,big-small);

}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll k,n;
  cin>>k>>n;
  ll a[n];
  f(n)
   cin>>a[i];
  sort(a,a+n);
  cout<<solve(a,n,k)<<endl;
 }
 return 0;
}
