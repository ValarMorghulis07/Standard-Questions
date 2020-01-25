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

ll ans;

void mergeit(ll a[],ll l,ll mid,ll r)
{
 ll n1=mid-l+1;
 ll n2=r-mid;
 ll L[n1],R[n2];
 for(ll i=0;i<n1;i++)
    L[i]=a[l+i];
 for(ll j=0;j<n2;j++)
    R[j]=a[mid+1+j];
 ll p=0,q=0,k=l;
 while(p<n1 && q<n2)
 {
  if(L[p]<=R[q])
  {
    a[k++]=L[p];
    p++;
  }
  else
  {
    ans+=(n1-p);
    a[k++]=R[q];
    q++;
  }
 }
 while(p<n1)
 {
  a[k++]=L[p];
    p++;
 }
 while(q<n2)
 {
  a[k++]=R[q];
    q++;
 }
}

void mergesort(ll a[],ll l ,ll r)
{
 if(r>l)
 {
  ll mid=l+(r-l)/2;
  mergesort(a,l,mid);
  mergesort(a,mid+1,r);

  mergeit(a,l,mid,r);
 }
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
 ans=0;
  ll n;
  cin>>n;
  ll a[n];
  f(n)
   cin>>a[i];
  mergesort(a,0,n-1);
  cout<<ans<<endl;

 }
 return 0;
}
