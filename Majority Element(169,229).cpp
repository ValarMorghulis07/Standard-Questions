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
