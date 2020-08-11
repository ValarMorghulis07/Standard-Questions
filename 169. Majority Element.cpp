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
