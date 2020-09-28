//33. Search in Rotated Sorted Array

class Solution {
public:
    int bs(vector<int>& nums,int lo,int hi,int x)
    {
     if(lo>hi)
         return -1;
     int mid=(lo+hi)>>1;
     if(nums[mid]==x)
         return mid;
     if(nums[lo]<=nums[mid])//nums[l...mid] is sorted
     {
      if(x>=nums[lo] && x<=nums[mid])
          return bs(nums,lo,mid-1,x);
      else
          return bs(nums,mid+1,hi,x);
     }
     else //nums[mid+1...h] is sorted
     {
      if(x>=nums[mid] && x<=nums[hi])
          return bs(nums,mid+1,hi,x);
      else
          return bs(nums,lo,mid-1,x);
     }
    }
    int search(vector<int>& nums, int target)
    {
     int n=nums.size();
     if(n==0)
         return -1;
     int idx=bs(nums,0,n-1,target);
     return idx;
    }
};

// 81. Search in Rotated Sorted Array II

class Solution {
public:
    // (o(logn) on average, o(n) worst case)
    int bs(vector<int>& nums,int lo,int hi,int x)
    {
     if(lo>hi)
         return -1;
     int mid=(lo+hi)>>1;
     if(nums[mid]==x)
         return mid;
     while(lo<hi && nums[lo]==nums[mid] && nums[mid]==nums[hi])// for this [1,3,1,1,1] and x=3--> it is done to make the range sorted,if we dont do it may be we will not be able to find if element is present. 
        lo++,hi--;
     if(nums[lo]<=nums[mid])//nums[l...mid] is sorted
     {
      if(x>=nums[lo] && x<=nums[mid])
          return bs(nums,lo,mid-1,x);
      else
          return bs(nums,mid+1,hi,x);
     }
     else //nums[mid+1...h] is sorted
     {
      if(x>=nums[mid] && x<=nums[hi])
          return bs(nums,mid+1,hi,x);
      else
          return bs(nums,lo,mid-1,x);
     }
    }
    bool search(vector<int>& nums, int target)
    {
     int n=nums.size();
     if(n==0)
         return 0;
     int idx=bs(nums,0,n-1,target);
     return (idx!=-1) ? 1:0;

    }
};

// 852. Peak Index in a Mountain Array(n>=3)

class Solution {
public:
    int bs(vector<int>&nums,int lo,int hi)
    {
     if(lo>hi)
         return -1;
     int mid=(lo+hi)>>1;
     if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
         return mid;
     if(nums[mid]<nums[mid+1])
         return bs(nums,mid,hi);
     else
         return bs(nums,lo,mid);
    }
    int peakIndexInMountainArray(vector<int>& arr)
    {
     int n=arr.size();
      return bs(arr,0,n-1);
    }
};

// Search in Bitonic Array!(IB)-->A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

int bitonicpoint(vector<int> &A,int lo,int hi)
{
 int mid=(lo+hi)>>1;
 if(A[mid]>A[mid-1] && A[mid]>A[mid+1])
  return mid;
 else if(A[mid]>A[mid-1])
   return bitonicpoint(A,mid,hi);
 else
   return bitonicpoint(A,lo,mid);
}

int bsinc(vector<int> &A,int lo,int hi,int x)
{
 while(lo<=hi)
 {
  int mid=(lo+hi)>>1;
  if(A[mid]==x)
   return mid;
  else if(A[mid]>x)
   hi=mid-1;
  else
   lo=mid+1;
 }
 return -1;
}

int bsdec(vector<int> &A,int lo,int hi,int x)
{
 while(lo<=hi)
 {
  int mid=(lo+hi)>>1;
  if(A[mid]==x)
   return mid;
  else if(A[mid]>x)
   lo=mid+1;
  else
   hi=mid-1;
 }
 return -1;
}

int Solution::solve(vector<int> &A, int B)
{
 int n=A.size();
 if(n==1)
  return (A[0]==B) ? 0:-1;
 int bp=bitonicpoint(A,0,n-1);
 //cout<<bp;
 if(A[bp]==B)
  return bp;
 else if(A[bp]<B)
  return -1;
 int aa=bsinc(A,0,bp-1,B);
 int bb=bsdec(A,bp+1,n-1,B);
 if(aa!=-1)
  return aa;
 if(bb!=-1)
  return bb;

}

// 162. Find Peak Element

/*
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.
*/

class Solution {
public:
    int doit(vector<int>&nums,int lo,int hi)
    {
     if(lo>hi)
         return -1;
     int mid=(lo+hi)>>1;
     if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
         return mid;
     else if(nums[mid]<nums[mid+1])
         return doit(nums,mid,hi);
     else
         return doit(nums,lo,mid);
    }
    int findPeakElement(vector<int>& nums)
    {
     int n=nums.size();
     if(n==1)
         return 0;
     if(nums[0]>nums[1])
         return 0;
     if(nums[n-1]>nums[n-2])
         return n-1;
     int idx=doit(nums,0,n-1);
     return idx;

    }
};

// 153. Find Minimum in Rotated Sorted Array

class Solution {
public:
    int bs(vector<int>&nums,int lo,int hi)
    {
     while(lo<=hi)
     {
     int mid=(lo+hi)>>1;
     if(nums[mid]>nums[mid+1]) // mid is peak (3,4,5,1,2)
         return mid+1;
     if(nums[mid-1]>nums[mid]) // mid-1 is peak (4,5,1,2,3)
         return mid;
     if(nums[mid]>nums[0]) //  (2,3,4,5,1)
         lo=mid+1;
     else
         hi=mid-1; // (5,1,2,3,4)
     }
     return -1;
    }
    
    int findMin(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==1)
         return nums[0];
     if(n==2)
         return min(nums[0],nums[1]);
     if(nums[n-1]>nums[0]) // already sorted
         return nums[0];
     int idx=bs(nums,0,n-1);
     return nums[idx];
     }
};

// 154. Find Minimum in Rotated Sorted Array II

/*
worst case(If all the elements are same) take O(N).
Average case in O(log n) time.
*/

class Solution {
public:
    int bs(vector<int>&nums,int lo,int hi)
    {
     while(lo<hi)
     {
      int mid=(lo+hi)>>1;
      if(nums[mid]==nums[hi])
          hi--;
      else if(nums[mid]>nums[hi]) // (1,1,1,0,1)
          lo=mid+1;
      else
          hi=mid; // (1,0,1,1,1)
     }
     return nums[hi];
    }
    int findMin(vector<int>& nums)
    {
     int n=nums.size();
     if(n==1)
         return nums[0];
     if(n==2)
         return min(nums[0],nums[1]);
     if(nums[n-1]>nums[0]) // already sorted
         return nums[0];
     return bs(nums,0,n-1);
    
    }
};
