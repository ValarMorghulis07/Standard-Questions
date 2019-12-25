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

const ll N=1e3+7;
ll a[N][N];
ll m,n;

/*void BinarySearch(ll p,ll j_low,ll j_high,ll x)
{
 while(j_low<=j_high)
 {
  ll mid=(j_low+j_high)/2;
  if(a[p][mid]==x)
  {
   cout<<"found at"<<" "<<p<<" "<<mid<<endl;
   return;
  }
  else if(a[p][mid]>x)
    j_high=mid-1;
  else
    j_low=mid+1;
 }
 cout<<"Element Not found"<<endl;
}

void BinaryUtil1(ll x)
{
 if(m==1)
 {
  BinarySearch(0,0,n-1,x);
  return;
 }
 ll i_low=0,i_high=m-1,j_mid=n/2;
 while((i_low+1)<i_high)
 {
  ll i_mid=(i_low+i_high)/2;
  if(a[i_mid][j_mid]==x)
  {
   cout<<"found at"<<" "<<i_mid<<" "<<j_mid<<endl;
   return;
  }
  else if(a[i_mid][j_mid]>x)
    i_high=i_mid;
  else
    i_low=i_mid;
 }
 if(a[i_low][j_mid]==x)
  cout<<"found at"<<" "<<i_low<<" "<<j_mid<<endl;
 else if(a[i_high][j_mid]==x)
  cout<<"found at"<<" "<<i_high<<" "<<j_mid<<endl;
 else if(x<a[i_low][j_mid])
    BinarySearch(i_low,0,j_mid-1,x);
 else if(x>a[i_low][j_mid] && x<=a[i_low][n-1])
    BinarySearch(i_low,j_mid+1,n-1,x);
 else if(x<a[i_high][j_mid])
    BinarySearch(i_high,0,j_mid-1,x);
 else
    BinarySearch(i_high,j_mid+1,n-1,x);
}*/

void BinaryUtil2(ll x)
{
 ll smallest=a[0][0],largest=a[m-1][n-1];
 if(x<smallest || x>largest)
 {
  cout<<"Element Not found"<<endl;
  return;
 }
 ll i=0,j=n-1;
 while(i<n && j>=0)
 {
  if(a[i][j]==x)
  {
   cout<<"found at"<<" "<<i<<" "<<j<<endl;
   return;
  }
  else if(a[i][j]>x)
    j--;
  else
    i++;
 }
 cout<<"Element Not found"<<endl;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>m>>n;
  f(m)
  {
   r(n)
   {
    cin>>a[i][j];
   }
  }
  for(ll p=0;p<m*n;p++)
  {
  ll x;
  cin>>x;
 // BinaryUtil1(x);//O(log n + log m);
  BinaryUtil2(x);//O(m+n);
  }
 }
 return 0;
}
