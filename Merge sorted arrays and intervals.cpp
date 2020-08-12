// 88. Merge Sorted Array

// O(n1+n2) && O(n1+n2)

void mergeArrays(int arr1[], int arr2[], int n1, 
                             int n2, int arr3[]) 
{ 
    int i = 0, j = 0, k = 0; 
  
    // Traverse both array 
    while (i<n1 && j <n2) 
    { 
        // Check if current element of first 
        // array is smaller than current element 
        // of second array. If yes, store first 
        // array element and increment first array 
        // index. Otherwise do same with second array 
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
