class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
     int n=nums.size();
     if(n==1)
         return nums[0];
     int idx=0,cnt=1;
     for(int i=1;i<n;i++)
     {
      if(nums[i]==nums[idx])
          cnt++;
      else
          cnt--;
      if(cnt==0)
      {
       idx=i;
       cnt=1;
      }
     }
     int sum=0;
     for(int i=0;i<n;i++)
     {
      if(nums[i]==nums[idx])
          sum++;
     }
     if(sum>n/2)
         return nums[idx];
     else
         return -1;
    }
};


// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
     vector<int>ans;
     int n=nums.size();
     if(n==1 || n==0)
         return nums;
     int first=INT_MAX,second=INT_MAX,cnt1=0,cnt2=0;
     for(int i=0;i<n;i++)
     {
      if(first==nums[i])
          cnt1++;
      else if(second==nums[i])
          cnt2++;
      else if(cnt1==0)
      {
        first=nums[i];
        cnt1=1;
      }
      else if(cnt2==0)
      {
        second=nums[i];
        cnt2=1;
      }
      else
      {
        cnt1--;
        cnt2--;
      }
     }
     cnt1=0;cnt2=0;
     for(int i=0;i<n;i++)
     {
      if(nums[i]==first)
          cnt1++;
      else if(nums[i]==second)
          cnt2++;
     }
     if(cnt1>n/3)
         ans.push_back(first);
     if(cnt2>n/3)
         ans.push_back(second);
     return ans;
     
    }
};

// --> max 2 elememts can be for answer

// Lucky Numbers

/*
Take the set of integers
1,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19,……

First, delete every second number, we get following reduced set.
1,3,5,7,9,11,13,15,17,19,…………

Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….

Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Therefore, set of lucky numbers is 1, 3, 7, 13,………
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

bool IsLucky(ll n)
{
 ll pos=n;
 ll zz=2;
 while(zz<=pos)
 {
  if(pos%zz==0)
    return false;
  else
  {
   pos-=pos/zz; // new position after deletion
   zz++;
  }
 }
 return true;
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  if(IsLucky(n))
    cout<<"1"<<endl;
  else
    cout<<"0"<<endl;
 }
}

