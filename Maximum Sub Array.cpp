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
 r(t)
 {
  ll n;
  cin>>n;
  ll a[n];
  f(n)
   cin>>a[i];
  ll index1,index2,start,maxx=INT_MIN,sum,len=INT_MIN;
  ll i;
  for(i=0;i<n;i++)
  {
   if(a[i]>=0)
   {
   start=i;
   sum=0;
   while(i<n && a[i]>=0)
   {
    sum+=a[i];
    i++;
   }
   if(sum>maxx)
   {
    maxx=sum;
    index1=start;
    index2=i-1;
    len=i-start;
   }
   else if(sum==maxx)
   {
    if(i-start>len)
    {
     maxx=sum;
     index1=start;
     index2=i-1;
     len=i-start;
    }
   }
  }
  }
  for(ll i=index1;i<=index2;i++)
    cout<<a[i]<<" ";
  cout<<"\n";
 }
 return 0;
}
