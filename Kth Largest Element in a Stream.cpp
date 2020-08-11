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
