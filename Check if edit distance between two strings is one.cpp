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

bool check(string s1,string s2)
{
 ll m=s1.length();
 ll n=s2.length();
 if(abs(m-n)>1)
    return false;
 ll i=0,j=0,cnt=0;
 while(i<m && j<n)
 {
  if(s1[i]!=s2[j])
  {
    if(m>n)
     i++;
    else if(n>m)
     j++;
    else
    {
     i++;
     j++;
    }
    cnt++;
  }
  else
  {
   i++;
   j++;
  }
 }
 if(i<m || j<n)
    cnt++;
 return (cnt==1);

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
  if(check(s1,s2))
    cout<<"One Away"<<endl;
  else
    cout<<"Oops"<<endl;
 }
 return 0;
}
