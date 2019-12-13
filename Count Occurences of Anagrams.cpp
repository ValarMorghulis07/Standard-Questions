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

/*void Anagrams1(string s1,string s2)
{
 ll a=s1.length();
 ll b=s2.length();

 ll cnt=0;
 for(ll i=0;i<=a-b;i++)
 {
  string str=s1.substr(i,b);
  sort(str.begin(),str.end());
  if(str==s2)
    cnt++;
 }
 cout<<cnt<<endl;
}*/
void Anagrams2(string s1,string s2)
{
 vector<ll>cnt1(26),cnt2(26);
 vector<ll>ans;
 for(ll i=0;i<s2.length();i++)
    cnt2[s2[i]-'a']++;
 for(ll i=0;i<s1.length();i++)
 {
  cnt1[s1[i]-'a']++;
  if(i>=s2.length())
   cnt1[s1[i-s2.length()]-'a']--;
  if(cnt1==cnt2)
   ans.pb(i-s2.length()+1);
 }
 cout<<ans.size()<<endl;

}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string s1,s2;
  cin>>s1>>s2;
  /*sort(s2.begin(),s2.end());
  Anagrams1(s1,s2);*/
  Anagrams2(s1,s2);

 }
 return 0;
}
