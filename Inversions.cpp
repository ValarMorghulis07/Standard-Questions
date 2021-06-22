// 775. Global and Local Inversions

class Solution {
public:
    int bb;
    void merge(vector<int>&A,int l,int mid,int r)
    {
     int n1=mid-l+1,n2=r-mid;
     int L[n1],R[n2];
     for(int i=0;i<n1;i++)
         L[i]=A[l+i];
     for(int i=0;i<n2;i++)
         R[i]=A[mid+1+i];
     int p=0,q=0,k=l;
     while(p<n1 && q<n2)
     {
      if(L[p]<=R[q])
        A[k++]=L[p++];
      else
      {
        bb+=(n1-p);
        A[k++]=R[q++];
      }
      
     }
     while(p<n1)
         A[k++]=L[p++];
     while(q<n2)
         A[k++]=R[q++];
        
    }
    void mergesort(vector<int>&A,int l,int r)
    {
     if(r>l)
     {
      int mid=l+(r-l)/2;
      mergesort(A,l,mid);
      mergesort(A,mid+1,r);
      merge(A,l,mid,r);
     }
    }
    
    bool isIdealPermutation(vector<int>& A)
    {
     int n=A.size();
     int aa=0;
     bb=0;
     for(int i=0;i<n-1;i++)
     {
      if(A[i]>A[i+1])
          aa++;
     }
     mergesort(A,0,n-1);
     //cout<<aa<<" "<<bb;
     if(aa==bb)
         return true;
     else
         return false;
    }
};

// 315. Count of Smaller Numbers After Self --> [5,2,6,1]

class Solution {
public:
    void Merge(pair<int,int> temp[],vector<int>& ans,int lo,int mid,int hi)
    {
     int n1=mid-lo+1,n2=hi-mid;
     pair<int,int>L[n1],R[n2];
     for(int i=0;i<n1;i++)
         L[i]=temp[lo+i];
     for(int i=0;i<n2;i++)
         R[i]=temp[mid+1+i];
     int p=0,q=0,k=lo,cnt=0;
     while(p<n1 && q<n2)
     {
      if(L[p].first<=R[q].first)
      {
       ans[L[p].second]+=cnt;
       temp[k++]=L[p++];
      }
      else
      {
       cnt++;
       temp[k++]=R[q++];
      }
     }
     while(p<n1)
     {
      ans[L[p].second]+=cnt;
      temp[k++]=L[p++];
     }
     while(q<n2)
         temp[k++]=R[q++];
         
    }
    
    void MergeSort(pair<int,int> temp[],vector<int>&ans,int lo,int hi)
    {
     if(lo<hi)
     {
      int mid=(lo+hi)>>1;
      MergeSort(temp,ans,lo,mid);
      MergeSort(temp,ans,mid+1,hi);
      Merge(temp,ans,lo,mid,hi);
     }
    }
    vector<int> countSmaller(vector<int>& nums) 
    {
     int n=nums.size();
     if(n==0)return {};
     vector<int>ans(n,0);
     pair<int,int>temp[n];
     for(int i=0;i<n;i++)
     {
       temp[i].first=nums[i];
       temp[i].second=i;
     }
     MergeSort(temp,ans,0,n-1);
     return ans;
       
    }
};


