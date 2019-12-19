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

ll bitonicpoint(ll a[],ll left,ll right)
{
 if(right>=left)
 {
  ll mid=(left+right)/2;
  if(a[mid]>a[mid+1] && a[mid]>a[mid-1])
    return mid;
  else if(a[mid]>a[mid+1])
    return bitonicpoint(a,left,mid-1);
  else
    return bitonicpoint(a,mid+1,right);
 }
 return -1;
}

ll b_search2(ll a[],ll left,ll right,ll k)
{
 if(right>=left)
 {
  ll mid=(left+right)/2;
  if(a[mid]==k)
    return mid;
  else if(a[mid]>k)
    return b_search2(a,mid+1,right,k);
  else
    return b_search2(a,left,mid-1,k);
 }
 return -1;
}

ll b_search1(ll a[],ll left,ll right,ll k)
{
 if(right>=left)
 {
  ll mid=(left+right)/2;
  if(a[mid]==k)
    return mid;
  else if(a[mid]>k)
    return b_search1(a,left,mid-1,k);
  else
    return b_search1(a,mid+1,right,k);
 }
 return -1;
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
  ll k;
  cin>>k;
  ll zz=bitonicpoint(a,1,n-2);
  if(a[zz]==k)
    cout<<zz<<endl;
  else
  {
   ll pp=b_search1(a,0,zz-1,k);
   ll qq=b_search2(a,zz+1,n-1,k);
   if(pp!=-1)
    cout<<pp<<endl;
   else if(qq!=-1)
    cout<<qq<<endl;
   else
    cout<<"-1"<<endl;
  }



 }
 return 0;

}
