class Solution {
public:
    bool CheckInRow(vector<vector<char>>& board,char num,int row)
    {
     int cnt=0;
     for(int col=0;col<9;col++)
     {
      if(board[row][col]==num)
          cnt++;
     }
     return (cnt!=1);
    }

    bool CheckInCol(vector<vector<char>>& board,char num,int col)
    {
     int cnt=0;
     for(int row=0;row<9;row++)
     {
      if(board[row][col]==num)
         cnt++;
     }
     return (cnt!=1);
    }

     bool CheckInBox(vector<vector<char>>& board,char num,int boxstartrow,int boxstartcol)
    {
     int cnt=0;
     for(int row=0;row<3;row++)
     {
      for(int col=0;col<3;col++)
      {
       if(board[row+boxstartrow][col+boxstartcol]==num)
          cnt++;
      }
     }
      return (cnt!=1);
    }

    bool IsSafe(vector<vector<char>>& board,char num,int row,int col)
    {
     return (CheckInRow(board,num,row) || CheckInCol(board,num,col) || CheckInBox(board,num,row-row%3,col-col%3));
    }







    bool isValidSudoku(vector<vector<char>>& board)
    {
     for(int i=0;i<board.size();i++)
     {
      for(int j=0;j<board[i].size();j++)
      {
       if(board[i][j]!='.' && IsSafe(board,board[i][j],i,j))
           return false;
      }
     }
        return true;
    }
};
