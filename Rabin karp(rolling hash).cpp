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
ll FCB=1e9+9;
ll prime=31;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

/*
O(m+n)(Average and Best)
O(m*n) (Worst)
*/

const ll N=1e5+5;
ll power[N];


void doit(string str)
{
 ll n=str.length();
 power[0]=1;
 for(ll i=1;i<n;i++)
    power[i]=((power[i-1]%FCB)*(prime%FCB))%FCB;
}

ll CreateHash(string str,ll m) //O(pat.length())
{
 ll res=0;
 rep(i,0,m)
 {
  res+=(str[i]*power[i]);
  res%=FCB;
 }

 return res;
}

ll RollingHash(string str,ll idx1,ll idx2,ll OldHash,ll m) //O(1)
{
 ll NewHash=OldHash-str[idx1];
 NewHash/=prime;
 NewHash+=(str[idx2]*power[m-1]);
 NewHash%=FCB;
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
  if(pat.length()>str.length())
  {
   cout<<"-1"<<"\n";
   continue;
  }
  doit(str);
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


}
/*
1
aabaaabaaac
aabaaac
*/

// KMP

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
  while(j>=0 && pat[i]!=pat[j])// length of the longest suffix which is also prefix in the pattern and reset value at index gives last prefix index
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
  while(j>=0 && str[i]!=pat[j])// suffix from string and prefix from pattern ,hence no need to revisit suffix
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
 //O(n) (Worst Case)
 return 0;
}

// 1392. Longest Happy Prefix

/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s. Return the longest happy prefix of s 
*/


const int N=1e5+7;
int reset[N];
class Solution {
public:
    string KMP(string pat)
    {
     int i=0,j=-1;
     while(i<pat.length())
     {
      while(j>=0 && pat[i]!=pat[j])
          j=reset[j];
      i++;
      j++;
      reset[i]=j;
      
     }
    
     return pat.substr(0,reset[pat.length()]);// since suffix will be till its last pos in pat
    }
    string longestPrefix(string s)
    {
     int n=s.length();
     if(n==0 || n==1)
         return "";
     for(int i=0;i<N;i++)
         reset[i]=-1;
     return KMP(s);
     
     
    }
};
