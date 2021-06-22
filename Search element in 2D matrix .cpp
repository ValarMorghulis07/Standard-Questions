// 240. Search a 2D Matrix II

/*
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

/* 
grid[][]={
          {1,3,5,7}
          {10,11,16,20}
          {23,30,34,60}
          }
*/

class Solution {
public:
    bool bs(vector<vector<int>>& matrix,int x) // O(m+n)
    {
     int m=matrix.size();
     int n=matrix[0].size();
     if(x<matrix[0][0] || x>matrix[m-1][n-1])
         return 0;
     int i=0,j=n-1;
     while(i<m && j>=0)
     {
      if(matrix[i][j]==x)
          return true;
      else if(matrix[i][j]>x)
          j--;
      else
          i++;
     }
     return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
     int m=matrix.size();
     if(m==0)
         return 0;
     int n=matrix[0].size();
     if(n==0)
         return 0;
     return bs(matrix,target);
    }
};

// 74. Search a 2D Matrix --> ( It can be done in upper way in O(m+n) complexity)

/*
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/

class Solution {
public:
    bool bs1(vector<vector<int>>& matrix,int i,int lo,int hi,int x)
    {
     while(lo<=hi)
     {
      int mid=(lo+hi)>>1;
      if(matrix[i][mid]==x)
          return true;
      else if(matrix[i][mid]>x)
          hi=mid-1;
      else
          lo=mid+1;
     }
     return false;
    }
    
    bool bs(vector<vector<int>>& matrix,int x)
    {
     int m=matrix.size();
     int n=matrix[0].size();
     if(m==1)
      return bs1(matrix,0,0,n-1,x);
     int i_low=0,i_high=m-1;
     int j_mid=n/2;
     while(i_low+1<i_high)
     {
      int i_mid=(i_low+i_high)>>1;
      if(matrix[i_mid][j_mid]==x)
          return true;
      else if(matrix[i_mid][j_mid]>x)
          i_high=i_mid;
      else
          i_low=i_mid;
     }
     if(matrix[i_low][j_mid]==x) // middle of first row
         return true;
     else if(matrix[i_high][j_mid]==x) // middle of second row
         return true;
     else if(x>=matrix[i_low][0] && x<matrix[i_low][j_mid]) // first half in first row
         return bs1(matrix,i_low,0,j_mid-1,x);
     else if(x>matrix[i_low][j_mid] && x<=matrix[i_low][n-1]) // // second half in first row
         return bs1(matrix,i_low,j_mid+1,n-1,x);
     else if(x>=matrix[i_high][0] && x<matrix[i_high][j_mid]) // first half in second row
         return bs1(matrix,i_high,0,j_mid-1,x);
     else                                                   // second half in second row
         return bs1(matrix,i_high,j_mid+1,n-1,x);
     return false;
     
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
     int m=matrix.size();
     if(m==0)
         return 0;
     int n=matrix[0].size();
     return bs(matrix,target);
    }
};

/*
Time complexity: O(log n + log m). O(Log m) time is required to find the two desired rows. 
Then O(Log n) time is required for binary search in one of the four parts with size equal to n/2.
*/
