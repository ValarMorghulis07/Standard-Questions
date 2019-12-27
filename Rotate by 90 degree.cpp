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

/*void RotateWithSpace()
{
 ll temp[n][n];
 f(n)
 {
  r(n)
  {
   temp[i][j]=a[j][n-1-i];
  }
 }
 f(n)
 {
  r(n)
  {
   cout<<temp[i][j]<<" ";
  }
  cout<<"\n";
 }
}*/

void RotateWithoutSpace()
{
 for(ll i=0;i<n;i++)
 {
  for(ll j=i;j<n;j++)
  {
    swap(a[i][j],a[j][i]);
  }
 }
 for(ll i=0;i<n;i++)
 {
  for(ll j=0;j<n/2;j++)
  {
   swap(a[j][i],a[n-1-j][i]);
  }
 }
 f(n)
 {
  r(n)
  {
   cout<<a[i][j]<<" ";
  }
  cout<<"\n";
 }

}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n;
  f(n)
  {
    r(n)
    {
     cin>>a[i][j];
    }
  }
  //RotateWithSpace();
  RotateWithoutSpace();
 }
 return 0;

}
