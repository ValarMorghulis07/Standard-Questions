#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define N 9
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

ll grid[N][N];

void print()
{
 f(N)
 {
  r(N)
  {
    cout<<grid[i][j]<<" ";
  }
  cout<<"\n";
 }
 cout<<"\n";
}
bool FindUnsignedLocation(ll &row,ll &col)
{
 for(row=0;row<N;row++)
 {
  for(col=0;col<N;col++)
  {
    if(grid[row][col]==0)
        return true;
  }
 }
 return false;
}

bool CheckInRow(ll num,ll row)
{
  for(ll col=0;col<N;col++)
  {
    if(grid[row][col]==num)
        return true;
  }
  return false;
}

bool CheckInCol(ll num,ll col)
{
  for(ll row=0;row<N;row++)
  {
    if(grid[row][col]==num)
        return true;
  }
  return false;
}
bool CheckInBox(ll num,ll boxstartrow,ll boxstartcol)
{
 for(ll row=0;row<3;row++)
 {
  for(ll col=0;col<3;col++)
  {
   if(grid[row+boxstartrow][col+boxstartcol]==num)
     return true;
  }
 }
 return false;
}


bool IsSafe(ll num,ll row,ll col)
{
 return (!CheckInRow(num,row) && !CheckInCol(num,col) && !CheckInBox(num,row-row%3,col-col%3) && grid[row][col]==0);
}



bool SolveSudoku()
{
 ll row,col;
 if(!FindUnsignedLocation(row,col))
    return true;
 for(ll num=1;num<=N;num++)
 {
  if(IsSafe(num,row,col))
  {
   grid[row][col]=num;
   if(SolveSudoku())
     return true;
   grid[row][col]=0;

  }
 }
 return false;

}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  f(N)
  {
   r(N)
   {
    cin>>grid[i][j];
   }
  }
  if(SolveSudoku())
    print();
  else
    cout<<"Not Possible"<<endl;

 }
 return 0;
}
