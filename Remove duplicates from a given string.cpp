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

char *checkduplicate(char str[],ll n)
{
 ll index=0;

 for(ll i=0;i<n;i++)
 {
  ll p;
  for(p=0;p<i;p++)
   if(str[p]==str[i])
     break;

  if(p==i)
   str[index++]=str[i];
 }
 return str;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  char str[]="geeksforgeeks";
  ll n=sizeof(str)/sizeof(str[0]);
  cout<<checkduplicate(str,n)<<endl;

 }
 return 0;
}
