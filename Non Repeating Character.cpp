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

void solve(string str,ll n)
{
 vector<char>vec;
 queue<char>q;
 ll cnt[26]={0};
 for(ll i=0;i<n;i++)
 {
  q.push(str[i]);
  cnt[str[i]-'a']++;
  while(!q.empty())
  {
   if(cnt[q.front()-'a']>1)
    q.pop();
   else
   {
    vec.pb(q.front());
    break;
   }
  }
 }
 if(!q.empty())
  cout<<vec.back()<<endl;
 else
  cout<<"-1"<<endl;

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
  string str;
  cin>>str;
  solve(str,n);//In one traversal;
  /*
  map<char,ll>mp;
  f(str.length())
  {
   mp[str[i]]++;
  }
  ll ff=0;
  f(str.length())
  {
   if(mp[str[i]]==1)
   {
    ff=1;
    cout<<str[i]<<endl;
    break;
   }
  }
  if(ff==0)
   cout<<"-1"<<endl;
   */

 }
 return 0;
}
