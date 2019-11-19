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

const ll N=11;
ll a[N][N],n;
vector<ll>vec;

void print()
{
 f(n)
 {
  r(n)
  {
   cout<<a[i][j]<<" ";

  }
  cout<<"\n";
 }


}

bool IsSafe(ll row,ll col)
{
 for(ll i=0;i<col;i++)
 {
  if(a[row][i])
    return false;
 }
 for(ll i=row,j=col;i>=0 && j>=0;i--,j--)
 {
  if(a[i][j])
    return false;
 }
 for(ll i=row,j=col;i<n && j>=0;i++,j--)
 {
  if(a[i][j])
    return false;
 }
 return true;
}

bool backtrack(ll col)
{
 if(col>=n)
    return true;
 for(ll i=0;i<n;i++)
 {
  if(IsSafe(i,col))
  {
   a[i][col]=1;
   if(backtrack(col+1))
     return true;
   a[i][col]=0;

  }
 }
 return false;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n;
  mem(a,0);
  if(backtrack(0))
    print();
  else
    cout<<"-1"<<endl;
 }
 return 0;
}
