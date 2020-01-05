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

map<ll,ll>mp;

bool allsame(string str)
{
 ll first,i;
 for(i=0;i<26;i++)
 {
  if(mp[i]>0)
  {
   first=mp[i];
   break;
  }
 }
 for(ll j=i+1;j<26;j++)
 {
  if(mp[j]>0 && mp[j]!=first)
    return false;
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
  string str;
  cin>>str;
  for(ll i=0;i<str.length();i++)
    mp[str[i]-'a']++;
  if(allsame(str))
    cout<<"1"<<endl;
  else
  {
    ll ff=0;
   for(ll i=0;i<26;i++)
   {
    if(mp[i]>0)
    {
     mp[i]--;
     if(allsame(str))
     {
      cout<<"1"<<endl;
      ff=1;
      break;
     }
     mp[i]++;
    }

   }
   if(ff==0)
     cout<<"0"<<endl;
  }
  mp.clear();

 }
 return 0;
}
