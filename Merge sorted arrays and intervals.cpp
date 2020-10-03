// 88. Merge Sorted Array

// O(n1+n2) && O(n1+n2)

void mergeArrays(int arr1[], int arr2[], int n1, 
                             int n2, int arr3[]) 
{ 
    int i = 0, j = 0, k = 0; 
    while (i<n1 && j <n2) 
    { 
      
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    } 
  
    // Store remaining elements of first array 
    while (i < n1) 
        arr3[k++] = arr1[i++]; 
  
    // Store remaining elements of second array 
    while (j < n2) 
        arr3[k++] = arr2[j++]; 
} 

// in O(1) space

/*
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
*/

class Solution {
public:
 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
      int i=m-1,j=n-1,tar=m+n-1;
      while(j>=0)
      {
       if(i>=0 && nums1[i]>nums2[j])
           nums1[tar]=nums1[i],i--;
       else
           nums1[tar]=nums2[j],j--;
       tar--;
      }
      
    }
};

// Merge k sorted arrays in O(N Log k) time.

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

const ll N=1e3+5;
ll a[N][N];
ll k,n;

void MergeSortedArray()
{
 vector<ll>ans;
 priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>>pq;
 for(ll i=0;i<k;i++)
    pq.push(m_p(a[i][0],m_p(i,0)));
 while(!pq.empty())
 {
  ll u=pq.top().first;
  ll v=pq.top().second.first;
  ll w=pq.top().second.second;
  pq.pop();
  ans.pb(u);
  if(w+1<n)
    pq.push(m_p(a[v][w+1],m_p(v,w+1)));
 }
 f(ans.size())
  cout<<ans[i]<<" ";
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>k>>n;
  f(k)
  {
   r(n)
   {
    cin>>a[i][j];
   }
  }
  MergeSortedArray();
  cout<<"\n";
 }
 return 0;
}

// 378. Kth Smallest Element in a Sorted Matrix

/*
// The space complexity of the above solutions will be O(N) and the time complexity will be O(min(K,N)+K∗logN).
    // Building a min-heap which takes O(n) time
    //  Heapify k times which takes O(k Logn) time.
*/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
     int n=matrix.size();
     int cnt=1;
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    for(int i=0;i<n;i++)
        pq.push(make_pair(matrix[i][0],make_pair(i,0)));
    
    while(!pq.empty())
    {
     int u=pq.top().first;
     int v=pq.top().second.first;
     int w=pq.top().second.second;
     pq.pop();
     if(cnt==k)
         return u;
     if(w+1<n)
         pq.push(make_pair(matrix[v][w+1],make_pair(v,w+1)));
     cnt++;
    }
    return matrix[n-1][n-1];
    
        
     
     
    }
};

--> 2
/*
time:= n*log(max element-min element)
space:= o(1)
*/
  
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
     int n=matrix.size();
     int lo=matrix[0][0],hi=matrix[n-1][n-1];
     while(lo<hi)
     {
      int mid=(lo+hi)>>1;
      int cnt=0;
      for(int i=0;i<n;i++) // count number of elements smaller than equal to mid
        cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
      if(cnt<k)
          lo=mid+1;
      else
          hi=mid;
     }
     return lo;
     
     
     
    }
};

// 56. Merge Intervals

vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
     vector<vector<int>>ans;
     sort(intervals.begin(),intervals.end());
     int n=intervals.size();
     if(n==0)return ans;
     int i=1,left=intervals[0][0],right=intervals[0][1];
     while(i<n)
     {
       if(intervals[i][0]>=left && intervals[i][0]<=right)
       {
         right=max(right,intervals[i][1]);
         i++;
         continue;
       }
       else
        {
         vector<int>vec;
         vec.push_back(left);
         vec.push_back(right);
         ans.push_back(vec);
         left=intervals[i][0];
         right=intervals[i][1];

        }
      i++;
     }

       vector<int>vec;
       vec.push_back(left);
       vec.push_back(right);
       ans.push_back(vec);
        return ans;
    }

// 57. Insert Interval

// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.

// n*log(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
     vector<vector<int>>ans;
     intervals.push_back(newInterval);
     sort(intervals.begin(),intervals.end());
     int left=intervals[0][0],right=intervals[0][1];
     int i=1;
     while(i<intervals.size())
     {
      if(intervals[i][0]>=left && intervals[i][0]<=right)
      {
       right=max(right,intervals[i][1]);
       i++;
       continue;
      }
      else
      {
       vector<int>vv;
       vv.push_back(left);
       vv.push_back(right);
       ans.push_back(vv);
       left=intervals[i][0];
       right=intervals[i][1];
       i++;
      }
     }
      vector<int>vv;
      vv.push_back(left);
      vv.push_back(right);
      ans.push_back(vv);
      return ans;
     }
};

// O(n)

/*
First, put all intervals that are to the left of the inserted interval.
Second, merge all intervals that intersect with the inserted interval.
Finally, put all intervals that are to the right of the inserted interval.
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
     vector<vector<int>>ans;
     int i=0;
     
     // First, put all intervals that are to the left of the inserted interval.
      
     while(i<intervals.size() && intervals[i][1]<newInterval[0])
     {
      vector<int>vv;
      vv.push_back(intervals[i][0]);
      vv.push_back(intervals[i][1]);
      ans.push_back(vv);
      i++;
     }
      
     // Second, merge all intervals that intersect with the inserted interval.
        
     while(i<intervals.size() && intervals[i][0]<=newInterval[1])
     {
      newInterval[0]=min(newInterval[0],intervals[i][0]);
      newInterval[1]=max(newInterval[1],intervals[i][1]);
      i++;
    
     }
     ans.push_back(newInterval);
      
     // Finally, put all intervals that are to the right of the inserted interval.
     
     while(i<intervals.size())
     {
      vector<int>vv;
      vv.push_back(intervals[i][0]);
      vv.push_back(intervals[i][1]);
      ans.push_back(vv);
      i++;
     }
        
     return ans;
    }
};
