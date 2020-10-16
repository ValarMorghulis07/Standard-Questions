// --->1st method

void leftRotate(int arr[], int n, int k)
{
    /* To get the starting point of rotated array */
    int mod = k % n;
 
    // Prints the rotated array from start position
    for (int i = 0; i < n; i++)
        cout << (arr[(mod + i) % n]) << " ";
 
    cout << "\n";
}

void RightRotate(int arr[], int n, int k)
{
    /* To get the starting point of rotated array */
    int mod = (n-k) % n;
 
    // Prints the rotated array from start position
    for (int i = 0; i < n; i++)
        cout << (arr[(mod + i) % n]) << " ";
 
    cout << "\n";
}

// --->2nd method

rotate(arr, arr + (k % n), arr + n); // anticlockwise

rotate(arr, arr + ((n-k) % n), arr + n); //clockwise

// 3rd method
     
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
