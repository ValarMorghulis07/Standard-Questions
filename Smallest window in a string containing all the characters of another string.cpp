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

void findstring(string str,string text)
{
 ll len1=str.length();
 ll len2=text.length();
 if(len2>len1)
 {
   cout<<"-1"<<endl;
   return;
 }


 map<char,ll>mp1,mp2;
 f(len2)
  mp2[text[i]]++;
 ll cnt=0,start=0,index=-1,min_len=INT_MAX;
 for(ll i=0;i<len1;i++)
 {
  mp1[str[i]]++;
  if(mp2[str[i]]!=0 && mp2[str[i]]>=mp1[str[i]])
    cnt++;
  if(cnt==len2)
  {
   while(mp1[str[start]]>mp2[str[start]] || mp2[str[start]]==0)
   {
    if(mp1[str[start]]>mp2[str[start]])
        mp1[str[start]]--;
    start++;
   }

  ll len_wndw=i-start+1;
  if(min_len>len_wndw)
  {
   min_len=len_wndw;
   index=start;
  }
  }
 }
 if(index==-1)
   cout<<"-1"<<endl;
 else
    cout<<str.substr(index,min_len)<<endl;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {

  string str,text;
  cin>>str>>text;
  findstring(str,text);
  // Brute Force
  /*ll a=str.length();
  ll b=text.length();
  map<char,ll>mp1;
  for(ll i=0;i<b;i++)
    mp1[text[i]]++;
  string ans="";
  ll zz=b;
  ll cnt=0,ff=0;
  while(cnt<a-b+1)
  {
    string s="";
    for(ll i=0;i<=a-zz;i++)
    {
     s=str.substr(i,zz);
     map<char,ll>mp;
     for(ll j=0;j<s.length();j++)
       mp[s[j]]++;
     ll gg=0;
     for(ll j=0;j<b;j++)
     {
      if(mp[text[j]]!=mp1[text[j]])
      {
        gg=1;
        break;
      }
     }
     if(gg==0)
     {
      ans=str.substr(i,zz);
      ff=1;
      break;
     }
     s="";

    }
    if(ff==1)
        break;
    zz++;
    cnt++;
  }
  if(ff==1)
    cout<<ans<<endl;
  else
    cout<<"-1"<<endl;*/

 }
 return 0;

}
