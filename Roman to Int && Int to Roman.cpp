//intToRoman

class Solution {
public:
    string intToRoman(int num) 
    {
     string ans="";
     int xx[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
     string str[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
     int idx=12;
     while(num)
     {
      int zz=num/xx[idx];
      num%=xx[idx];
      while(zz--)
          ans+=str[idx];
      idx--;
     }
     return ans;
    }
};

//Romantoint

class Solution {
public:
    int value(char ch)
    {
     if(ch=='I')
         return 1;
     if(ch=='V')
         return 5;
     if(ch=='X')
         return 10;
     if(ch=='L')
         return 50;
     if(ch=='C')
         return 100;
     if(ch=='D')
         return 500;
     if(ch=='M')
         return 1000;
     return -1;
     
    }
    int romanToInt(string s) 
    {
     int n=s.length();
     if(n==0)
         return 0;
     int res=0,idx=0;
     while(idx<n)
     {
      int v1=value(s[idx]);
      if(idx+1<n)
      {
       int v2=value(s[idx+1]);
       if(v1>=v2)
           res+=v1;
       else
         res+=v2-v1,idx++;
      }
      else
          res+=v1;
      idx++;
     }
     return res;
     
     
    }
};



