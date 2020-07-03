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



void KMP(string pat)
{

 ll n=pat.length();
 ll reset[n];
 reset[0]=0;
 ll i=1,j=0;
 while(i<n)
 {
  if(pat[i]==pat[j])
  {
   reset[i]=j+1;
   i++;
   j++;

  }
  else
  {
   if(j!=0)
    j=reset[j-1];
   else
    reset[i]=0,i++;
  }
 }
 cout<<reset[n-1]<<"\n";
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  string pat;
  cin>>pat;
  KMP(pat);

 }
 return 0;
}
