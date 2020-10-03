// 394. Decode String

class Solution {
public:
    
    string decodeString(string s) 
    {
     int n=s.length();
     stack<int>istk;
     stack<char>cstk;
     string temp="",res="";
     for(int i=0;i<n;i++)
     {
      int cnt=0;
         
      if(s[i]>='0' && s[i]<='9')
      {
       while(s[i]>='0' && s[i]<='9')
             cnt=cnt*10+s[i]-'0',i++;
       i--;
       istk.push(cnt);
      }
     
             
     else if(s[i]=='[')
     {
      if(s[i-1]>='0' && s[i-1]<='9')
          cstk.push(s[i]);
      else
          cstk.push(s[i]),istk.push(1);
     }
             
     else if(s[i]==']')
     {
      cnt=0;
      temp="";
      if(!istk.empty())
          cnt=istk.top(),istk.pop();
      while(!cstk.empty() && cstk.top()!='[')
      {
       temp=cstk.top()+temp;
       cstk.pop();
      }
      if(!cstk.empty() && cstk.top()=='[')
          cstk.pop();
      for(int j=0;j<cnt;j++)
          res=res+temp;
      for(int j=0;j<res.length();j++)
          cstk.push(res[j]);
      res="";
     }
     
    else
       cstk.push(s[i]);
             
    }
     string ans="";
     while(!cstk.empty())
     {
      ans=cstk.top()+ans;
      cstk.pop();
     }
     return ans;
    }
             
 };

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
