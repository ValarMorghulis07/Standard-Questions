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


string Multiply(string str1,string str2,ll ff)
{
 ll m=str1.length();
 ll n=str2.length();
 if(m==0 || n==0)
    return "0";
 ll index1=0,index2=0;
 vector<ll>a(m+n,0);
 for(ll i=m-1;i>=0;i--)
 {
  ll carry=0;
  index2=0;
  ll n1=str1[i]-'0';
  for(ll j=n-1;j>=0;j--)
  {
   ll n2=str2[j]-'0';
   ll sum=n1*n2+a[index1+index2]+carry;
   carry=sum/10;
   a[index1+index2]=sum%10;
   index2++;
  }
  if(carry>0)
    a[index1+index2]+=carry;
  index1++;
 }
 ll p=a.size()-1;
 while(p>=0 && a[p]==0)
    p--;
 if(p==-1)
    return "0";
 string ans="";
 if(ff==1)
    ans+='-';
 for(ll i=p;i>=0;i--)
    ans+=(to_string(a[i]));
 return ans;

}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  string s1,s2,str1,str2;
  cin>>s1>>s2;
  ll ff=0;
  if(s1[0]=='-' && s2[0]=='-')
  {

    str1=s1.substr(1);
    str2=s2.substr(1);
  }
  else if(s1[0]=='-' && s2[0]!='-')
  {
    ff=1;
    str1=s1.substr(1);
    str2=s2;
  }
  else if(s1[0]!='-' && s2[0]=='-')
  {
    ff=1;
    str1=s1;
    str2=s2.substr(1);
  }
  else
  {
    str1=s1;
    str2=s2;
  }

 cout<<Multiply(str1,str2,ff)<<endl;
 }
 return 0;
}
