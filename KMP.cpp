#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=1e5+7;
ll reset[N];
bool ff;

void KMPpreprocess(string pat)
{
 ll i=0,j=-1;
 while(i<pat.length())
 {
  while(j>=0 && pat[i]!=pat[j])
    j=reset[j];
  i++;
  j++;
  reset[i]=j;
 }
}

void KMPsearch(string str,string pat)
{
 KMPpreprocess(pat);
 ll i=0,j=0;
 while(i<str.size())
 {
  while(j>=0 && str[i]!=pat[j])
    j=reset[j];
  i++;
  j++;
  if(j==pat.length())
  {
   cout<<i-j<<" ";
   ff=1;
   j=reset[j];
  }
 }

}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  rep(i,0,N)
   reset[i]=-1;
  string str,pat;
  cin>>str>>pat;
  ff=0;
  KMPsearch(str,pat);
  if(!ff)
    cout<<"-1";
  cout<<"\n";
 }
 return 0;
}
