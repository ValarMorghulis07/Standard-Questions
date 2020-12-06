#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=4*1e6+7;
ll tree[N]; // 1 based indexing in tree[]

void buildTree(ll a[],ll node,ll s,ll e) //o(n)
{
 if(s>e)
    return;
 // base case-->leaf
 if(s==e)
 {
  tree[node]=a[s];
  return;
 }
 ll mid=(s+e)>>1;
 buildTree(a,2*node,s,mid);
 buildTree(a,2*node+1,mid+1,e);
 tree[node]=min(tree[2*node],tree[2*node+1]); 
}

void UpdateNode(ll a[],ll node,ll s,ll e,ll idx,ll val) // O(log(n))
{
 // No overlap
 if(idx<s || e<idx)
    return;
 // Complete overlap
 if(s==e)
 {
  tree[node]=val;
  return;
 }
 // partial overlap
 ll mid=(s+e)>>1;
 UpdateNode(a,2*node,s,mid,idx,val);
 UpdateNode(a,2*node+1,mid+1,e,idx,val);
 tree[node]=min(tree[2*node],tree[2*node+1]);
 return;
}

void UpdateRange(ll a[],ll node,ll s,ll e,ll l,ll r,ll inc) //O(n)
{
 // No overlap
 if(r<s || e<l)
    return;
 // complete overlap(leaf node)
 if(s==e)
 {
  tree[node]+=inc;
  return;
 }
 // partial overlap
 ll mid=(s+e)>>1;
 UpdateRange(a,2*node,s,mid,l,r,inc);
 UpdateRange(a,2*node+1,mid+1,e,l,r,inc);
 tree[node]=min(tree[2*node],tree[2*node+1]);
 return;
}

ll query(ll a[],ll node,ll s,ll e,ll l,ll r) // O(log(n))
{
 // No overlap
 if(r<s || e<l)
    return ESP;
 // Complete overlap
 if(l<=s && e<=r)
    return tree[node];
 // partial overlap
 ll mid=(s+e)>>1;
 ll left=query(a,2*node,s,mid,l,r);
 ll right=query(a,2*node+1,mid+1,e,l,r);
 return min(left,right);
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n,q;
  cin>>n>>q;
  ll a[n];
  rep(i,0,n)
   cin>>a[i];
  buildTree(a,1,0,n-1);
  while(q--)
  {
    ll x,y,z;
    cin>>x>>y>>z;
    if(x==1) // UpdateNode (here y is idx and z is val)
      UpdateNode(a,1,0,n-1,y,z);
    else if(x==2) // Update in a range (here range is [y,z] & we have to increment inc)
    {
     ll inc;
     cin>>inc;
     UpdateRange(a,1,0,n-1,y,z,inc);
    }
    else
      cout<<query(a,1,0,n-1,y,z)<<"\n";
  }

 }
 return 0;
}
