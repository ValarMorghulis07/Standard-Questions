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


void anti_clockwise(ll a[],ll n,ll k)
{
 for(ll i=k;i<k+n;i++)
    cout<<a[i%n]<<" ";
 cout<<"\n";
}

/*void clockwise(ll a[],ll n,ll p)
{
 for(ll i=p;i<p+n;i++)
    cout<<a[i%n]<<" ";
 cout<<"\n";
}*/


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n,k;
  cin>>n>>k;
  if(k>n)
    k=k%n;
  ll a[n];
  f(n)
   cin>>a[i];
  anti_clockwise(a,n,k);
  //clockwise(a,n,n-k);

 }
 return 0;

}


// clockwise

class Solution {
public:
    void doit(vector<int>& nums,int start,int end)//O(n) && o(1)
    {
     while(start<end)
     {
      int temp=nums[start];
      nums[start]=nums[end];
      nums[end]=temp;
      start++;
      end--;
     }
    }
    void rotate(vector<int>& nums, int k)
    {
     int n=nums.size();
     if(n==0)
         return;
     k%=n;
     /*int pp=n-k; if(anticlockwise then pp=k,&& rest will be same) O(n) && O(n)
     vector<int>vv;
     for(int i=pp;i<pp+n;i++)
        vv.push_back(nums[i%n]);
     for(int i=0;i<n;i++)
         nums[i]=vv[i];
     */
        
     doit(nums,0,n-1);
     doit(nums,0,k-1);
     doit(nums,k,n-1);
    }
};
