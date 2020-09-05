// 91. Decode Ways

class Solution {
public:
   
     int numDecodings(string s) 
    {
     int n=s.length();
     if(n==0)
         return 0;
     if(s[0]=='0')
         return 0;
     int dp[n+1];
     dp[0]=1;
     dp[1]=1;
     for(int i=2;i<=n;i++)
     {
      dp[i]=0;
      if(s[i-1]>'0') // If the last digit is not 0, then last digit must add to the number of words  
          dp[i]=dp[i-1];
      if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'7')) // If second last digit is smaller than 2 and last digit is smaller than 7,then last two digits form a valid character 
          dp[i]+=dp[i-2];
     }
     return dp[n];
         
    }     
    
};
