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


void doit(ll a[],ll n,ll mid1,ll mid2,ll zz)
{
  while(mid1>=0)
  {
    ll temp=a[mid1]+zz;
    zz=temp/10;
    temp=temp%10;
    a[mid1]=a[mid2]=temp;
    mid1--;
    mid2++;
  }
  if(zz)
  {
    cout<<zz<<" ";
    f(n)
     cout<<a[i]<<" ";

  }
  else
  {
    f(n)
      cout<<a[i]<<" ";
  }
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
  ll mid1,mid2;
  if(n & 1)
    mid1=n/2,mid2=mid1;
  else
   mid1=(n/2)-1,mid2=mid1+1;
  ll p=mid1,q=mid2;
  while(p>=0 && q<n)
  {
    if(a[p]==a[q])
        p--,q++;
    else if(a[p]>a[q])
    {
     doit(a,n,mid1,mid2,0);
     break;
    }
    else
    {
     doit(a,n,mid1,mid2,1);
     break;
    }

  }
  if(p==-1 && q==n)
    doit(a,n,mid1,mid2,1);
 }

 return 0;

}
