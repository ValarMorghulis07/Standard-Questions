 void setZeroes(vector<vector<int>>& matrix)
    {
      int row=matrix.size();
        if(row==0)
            return;
      int col=matrix[0].size();
      bool rr=false,cc=false;
      for(int i=0;i<row;i++)
      {
       for(int j=0;j<col;j++)
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

        for(int i=1;i<row;i++)
        {
          for(int j=1;j<col;j++)
          {
            if(matrix[i][0]==0 || matrix[0][j]==0)
              matrix[i][j]=0;
          }
        }
     if(rr)
     {
      for(int i=0;i<col;i++)
          matrix[0][i]=0;
     }
     if(cc)
     {
      for(int i=0;i<row;i++)
          matrix[i][0]=0;
     }
       // return matrix;
    }
