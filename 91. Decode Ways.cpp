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

// 639. Decode Ways II

// Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.


class Solution {
public:
    int fcb=1e9+7;
    int numDecodings(string s) 
    {
     int n=s.length();
     if(n==0)
         return 0;
     if(s[0]=='0')
         return 0;
     int dp[1+n];
     dp[0]=1;
     if(s[0]=='*')
         dp[1]=9;
     else
         dp[1]=1;
     for(int i=1;i<n;i++)
     {
      if(s[i]=='*')
      {
       dp[i+1]=9*dp[i];
       if(s[i-1]=='1')
           dp[i+1]=(dp[i+1]+9*dp[i-1])%fcb;
       else if(s[i-1]=='2')
           dp[i+1]=(dp[i+1]+6*dp[i-1])%fcb;
       else if(s[i-1]=='*')
           dp[i+1]=(dp[i+1]+15*dp[i-1])%fcb;
      }
      
      else
      {
       dp[i+1]=(s[i]!='0') ? dp[i] : 0;
       if(s[i-1]=='1' || (s[i-1]=='2' && s[i]<'7'))
           dp[i+1]=(dp[i+1]+dp[i-1])%fcb;
       else if(s[i-1]=='*')
       {
         if(s[i]<='6') // two choices(*--> can be 1 or 2)
             dp[i+1]=(dp[i+1]+2*dp[i-1])%fcb;
         else
             dp[i+1]=(dp[i+1]+dp[i-1])%fcb;
       }
        
      }
     }
     return dp[n];
    }
};
