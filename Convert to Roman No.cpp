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
  ll n;
  cin>>n;
  string thousands[]={"","M","MM","MMM","MMMM"};
  string hundreds[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","MC"};
  string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
  string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};

  string ans="";
  ans=ans+thousands[n/1000];
  n=n%1000;
  ans=ans+hundreds[n/100];
  n=n%100;
  ans=ans+tens[n/10];
  n=n%10;
  ans=ans+ones[n/1];
  n=n%1;
  cout<<ans<<endl;
 }
 return 0;
}
