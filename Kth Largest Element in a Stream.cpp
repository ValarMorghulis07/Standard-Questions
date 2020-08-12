// 703. Kth Largest Element in a Stream

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int zz;
    KthLargest(int k, vector<int>& nums)
    {
     zz=k;
     for(int i=0;i<nums.size();i++)
     {
      pq.push(nums[i]);
      if(pq.size()>k)
          pq.pop();
     }
    }

    int add(int val)
    {
     pq.push(val);
     if(pq.size()>zz)
         pq.pop();
     return pq.top();
    }
};


// 215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
     priority_queue<int,vector<int>,greater<int>>pq;
     for(int i=0;i<nums.size();i++)
     {
      pq.push(nums[i]);
      if(pq.size()>k)
          pq.pop();
     }
     return pq.top();
    }
};

// 347. Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
      int n=nums.size();
      if(n==k)//O(n)
          return nums;
      vector<int>ans;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap
      unordered_map<int,int>mp;
      for(auto xx:nums)
          mp[xx]++;
      for(auto xx:mp)
      {
       pq.push(make_pair(xx.second,xx.first));
       if(pq.size()>k)
           pq.pop();
        
      }
      while(!pq.empty())
      {
       ans.push_back(pq.top().second);
       pq.pop();
      }
          
      
    return ans;
      
    }
};
