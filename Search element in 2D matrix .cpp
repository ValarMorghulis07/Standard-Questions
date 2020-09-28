// 240. Search a 2D Matrix II

/*
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
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
