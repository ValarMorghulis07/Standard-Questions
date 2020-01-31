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




int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  char ch[9];
  ll xx=0,oo=0;
  f(9)
  {
   cin>>ch[i];
   if(ch[i]=='X')
      xx++;
   else
      oo++;
  }
 ll aa=0,bb=0;
 if(xx-oo!=1)
    cout<<"Invalid"<<endl;
  else
  {
    // In Row
    ll p=0;
    while(p<9)
    {
      if(ch[p]=='X' && ch[p+1]=='X' && ch[p+2]=='X')
          aa++;
      else if(ch[p]=='O' && ch[p+1]=='O' && ch[p+2]=='O')
          bb++;
      p+=3;
    }

    //In Column
    ll q=0;
    while(q<3)
    {
      if(ch[q]=='X' && ch[q+3]=='X' && ch[q+6]=='X')
          aa++;
      else if(ch[q]=='O' && ch[q+3]=='O' && ch[q+6]=='O')
          bb++;
      q++;
    }

    // In Main Diagonal
    if(ch[0]=='X' && ch[4]=='X' && ch[8]=='X')
        aa++;
    if(ch[0]=='O' && ch[4]=='O' && ch[8]=='O')
        bb++;

     // In Reverse  Diagonal
    if(ch[2]=='X' && ch[4]=='X' && ch[7]=='X')
        aa++;
    if(ch[2]=='O' && ch[4]=='O' && ch[7]=='O')
        bb++;

    if(bb>=1)
        cout<<"Invalid"<<endl;
    else
        cout<<"Valid"<<endl;



  }
 }
 return 0;

}
