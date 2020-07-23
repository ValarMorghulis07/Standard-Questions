class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
     int m=matrix.size();
     if(m==0)
         return;
     int n=matrix[0].size();
     /*int vv[m][n]; //O(m*n) space
     unordered_map<int,bool>mpr,mpc;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
        if(matrix[i][j]==0)
        {
          mpr[i]=1;
          mpc[j]=1;   
        }
        vv[i][j]=matrix[i][j];
      }
     }
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(mpr[i])
           vv[i][j]=0;
       if(mpc[j])
           vv[i][j]=0;
      
      }
     }
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       matrix[i][j]=vv[i][j];
      
      }
     }
     */
     bool rr=0,cc=0;// O(1)  space
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(matrix[i][j]==0)
       {
         if(i==0)
             rr=true;
         if(j==0)
             cc=true;
         matrix[i][0]=0;
         matrix[0][j]=0;
       }
      }
     }
     for(int i=1;i<m;i++)
     {
      for(int j=1;j<n;j++)
      {
       if(matrix[i][0]==0 || matrix[0][j]==0)
           matrix[i][j]=0;
      }
     }
     if(rr)
     {
      for(int i=0;i<n;i++)
          matrix[0][i]=0;
     }
        
     if(cc)
     {
      for(int i=0;i<m;i++)
          matrix[i][0]=0;
     }
     
     
     
    }
};
