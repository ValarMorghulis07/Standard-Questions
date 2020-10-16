/*
Given two arrays A1[] and A2[], sort A1 in such a way that the relative order among the elements will be same as those are in A2. For the elements not present in A2, append them at last in sorted order. 
Example: 

Input: A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
       A2[] = {2, 1, 8, 3}
Output: A1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}
*/

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
  ll n,m;
  cin>>n>>m;
  ll a[n],b[m];
  map<ll,ll>mp;
  f(n)
  {
   cin>>a[i];
   mp[a[i]]++;
  }
  f(m)
  {
   cin>>b[i];
   if(mp[b[i]]>0)
   {
    ll zz=mp[b[i]];
    r(zz)
    {
     cout<<b[i]<<" ";
     mp[b[i]]--;
    }
   }
  }
  for(auto itr=mp.begin();itr!=mp.end();++itr)
  {
   while(itr->second!=0)
   {
    cout<<itr->first<<" ";
    (itr->second)--;
   }

  }
  cout<<"\n";

 }
 return 0;
}

// Sorting Elements of an Array by Frequency

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
  ll a[n];
  map<ll,ll>mp;
  multimap<ll,ll>mm;
  f(n)
  {
    cin>>a[i];
    mp[a[i]]++;
  }
  for(auto itr=mp.rbegin();itr!=mp.rend();++itr)
  {
   mm.insert(pair<ll,ll>(itr->second,itr->first));
  }
  for(auto itr=mm.rbegin();itr!=mm.rend();++itr)
  {
    ll x=itr->first;
    while(x--)
      cout<<itr->second<<" ";
  }
  cout<<"\n";
 }
 return 0;
}
