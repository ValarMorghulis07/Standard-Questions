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
  ll n,k;
  cin>>n>>k;
  ll a[n];
  ll sum=0;
  f(n)
  {
   cin>>a[i];
   sum+=a[i];
  }
  sort(a,a+n);
  if(k==0)
  {
    cout<<sum<<" "<<sum<<endl;
  }
  else
  {
   ll p=0,q=n-1;
   ll sum1=0,sum2=0;
   while(q>=p)
   {
    sum1+=a[p];
    p++;
    q+=-k;
   }
   p=0,q=n-1;
   while(q>=p)
   {
    sum2+=a[q];
    q--;
    p+=k;
   }
   cout<<sum1<<" "<<sum2<<endl;
  }
 }
 return 0;
}
