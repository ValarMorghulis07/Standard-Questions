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


bool check(string str)//O(n)
{
 ll n=str.length();
 stack<char>stk;
 for(ll i=0;i<n;i++)
 {
  if(str[i]=='(' || str[i]=='{' || str[i]=='[')
  {
   stk.push(str[i]);
   continue;
  }
  if(stk.empty())
    return false;
  else if(str[i]==']')
  {
   char x=stk.top();
   stk.pop();
   if(x=='{' || x=='(')
     return false;
  }
  else if(str[i]==')')
  {
   char x=stk.top();
   stk.pop();
   if(x=='{' || x=='[')
     return false;
  }
  else if(str[i]=='}')
  {
   char x=stk.top();
   stk.pop();
   if(x=='[' || x=='(')
     return false;
  }
 }
 if(stk.empty())
    return true;
 else
    return false;
}

bool checkvalid(string &str,ll &cnt,ll &p,ll &q,char ch)//O(1)
{
 cnt--;
 if(q>-1 && str[q]==ch)
 {
  str[p]='#';
  str[q]='#';
  while(q>=0 && str[q]=='#')
    q--;
  p++;
  return true;
 }
 else
   return false;

}

bool IsValid(string str)
{
 ll p=0,q=-1,cnt=0;
 if(str.length()==0)
    return true;
 else
 {

  while(p<str.length())
  {
   if(str[p]==')')
   {
    if(!checkvalid(str,cnt,p,q,'('))
        return false;
   }
   else if(str[p]==']')
   {
    if(!checkvalid(str,cnt,p,q,'['))
        return false;
   }
   else if(str[p]=='}')
   {
    if(!checkvalid(str,cnt,p,q,'{'))
        return false;
   }
   else
   {
    q=p;
    p++;
    cnt++;
   }

  }
  if(cnt!=0)
    return false;
 return true;
 }

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
  if(IsValid(str))
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
 }
 return 0;
}
