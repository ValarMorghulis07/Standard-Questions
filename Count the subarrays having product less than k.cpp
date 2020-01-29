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


void calculate(ll a[],ll n,ll k)
{
 ll start=0,sum=0,len=0,j,zz=1;
 for(j=0;j<n;j++)
 {
  zz=zz*a[j];
  while(start<j && zz>=k)
  {
   zz/=a[start];
   start++;
  }
  if(zz<k)
  {
   len=j-start+1;
   sum+=len;
  }
 }
 cout<<sum<<endl;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n,k;
  cin>>n>>k;
  ll a[n];
  f(n)
   cin>>a[i];
  calculate(a,n,k);
 }
 return 0;


}
