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

ll CreateHash(string str,ll m) //O(pat.length()
{
 ll res=0;
 rep(i,0,m)
  res+=(str[i]*pow(prime,i));
 return res;
}

ll RollingHash(string str,ll idx1,ll idx2,ll OldHash,ll m) //O(1)
{
 ll NewHash=OldHash-str[idx1];
 NewHash/=prime;
 NewHash+=(str[idx2]*pow(prime,m-1));
 return NewHash;


}

bool CheckEqual(string s1,string s2,ll start1,ll end1,ll start2,ll end2) //O(m)
{
 if(end1-start1!=end2-start2)
    return false;
 while(start1<=end1 && start2<=end2)
 {
  if(s1[start1]!=s2[start2])
    return false;
  start1++;
  start2++;
 }
 return true;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  string str,pat;
  cin>>str>>pat;
  ll PatHash=CreateHash(pat,pat.length());
  ll StrHash=CreateHash(str,pat.length());
  bool ff=0;
  for(ll i=0;i<=str.length()-pat.length();i++)
  {
   if(PatHash==StrHash && CheckEqual(str,pat,i,i+pat.length()-1,0,pat.length()-1))
   {
    cout<<i<<" ";
    ff=1;
   }

   if(i<str.length()-pat.length())
     StrHash=RollingHash(str,i,i+pat.length(),StrHash,pat.length());
  }
  if(!ff)
    cout<<"-1";
  cout<<"\n";
 }
 return 0;
 //O(m+n)(Average and Best)
 //O(m*n) (Worst)

}
