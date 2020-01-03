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

void solve(string str)
{
 ll check=0,ff=0;
 for(ll i=0;i<str.length();i++)
 {
  ll val=str[i]-'a';
  if((check & (1<<val))>0)
  {
    cout<<str[i]<<endl;
    ff=1;
    break;
  }
  check|=(1<<val);
 }
 if(ff==0)
    cout<<"-1"<<endl;
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string str;
  cin>>str;
  solve(str);//o(1) space
 /* map<char,ll>mp;
  ll ff=0;
  f(str.length())
  {
   mp[str[i]]++;
   if(mp[str[i]]>1)
   {
    cout<<str[i]<<endl;
    ff=1;
    break;
   }
  }
  if(ff==0)
    cout<<"-1"<<endl;*/
 }
 return 0;
}
