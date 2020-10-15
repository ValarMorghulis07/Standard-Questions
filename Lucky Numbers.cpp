/*
Take the set of integers
1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,……

First, delete every second number, we get following reduced set.
1,3,5,7,9,11,13,15,17,19,…………

Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….

Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Therefore, set of lucky numbers is 1, 3, 7, 13,………
*/

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

bool IsLucky(ll n)
{
 ll pos=n;
 ll zz=2;
 while(zz<=pos)
 {
  if(pos%zz==0)
    return false;
  else
  {
   pos-=pos/zz;
   zz++;
  }
 }
 return true;
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
  if(IsLucky(n))
    cout<<"1"<<endl;
  else
    cout<<"0"<<endl;
 }
}
