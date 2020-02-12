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
ll ESP=1e18;
ll INF=1e9+7;


const ll N=1e6+7;
ll spf[N];
vector<ll>ans;

void primefactors()//o(sqrt(n))
{
 ll zz=N;
 while(zz%2==0)
 {
  cout<<"2"<" ";
  N/=2;
 }
 for(ll i=3;i<=sqrt(zz);i+=2)
 {
  while(zz%i==0)
  {
   cout<<i<<" ";
   zz/=i;
  }
 }
 if(zz>2)
    cout<<zz<<" ";
}

void sieve()//o(log(log(n))
{
 spf[1]=1;
 for(ll i=2;i<N;i++)
   spf[i]=i;
 for(ll i=4;i<N;i+=2)
    spf[i]=2;
 for(ll i=3;i*i<N;i++)
 {
  if(spf[i]==i)
  {
    for(ll j=i*i;j<N;j+=i)
    {
     if(spf[j]==j)
        spf[j]=i;
    }
  }
 }

}

void getprimefactors(N)
{
 while(x!=1)
 {
  ans.pb(spf[x]);
  x/=spf[x];
 }
}


int main()
{
 hs;
 primefactors();
 sieve();
 getprimefactors();
 return 0;
}
