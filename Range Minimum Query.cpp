#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll ESP=1e18;
ll INF=1e9+7;

const ll N=4*1e5+7;
ll tree[N];

void build(ll a[],ll node,ll start,ll endd)
{
 if(start==endd)
    tree[node]=a[start];
 else
 {
  ll mid=(start+endd)/2;
  build(a,2*node+1,start,mid);
  build(a,2*node+2,mid+1,endd);
  tree[node]=min(tree[2*node+1],tree[2*node+2]);
 }
}

void update(ll a[],ll node,ll start,ll endd,ll idx,ll val)
{
 if(start==endd)
 {
  a[idx]=val;
  tree[node]=val;
 }
 else
 {
  ll mid=(start+endd)/2;
  if(start<=idx && idx<=mid)
    update(a,2*node+1,start,mid,idx,val);//0's index
  else
    update(a,2*node+2,mid+1,endd,idx,val);
  tree[node]=min(tree[2*node+1],tree[2*node+2]);
 }
}

ll query(ll a[],ll node,ll start,ll endd,ll l,ll r)
{
 if(l>endd or r<start)
    return ESP;
 if(l<=start && endd<=r)
    return tree[node];
 ll mid=(start+endd)/2;
 ll p1=query(a,2*node+1,start,mid,l,r);
 ll p2=query(a,2*node+2,mid+1,endd,l,r);
 return min(p1,p2);
}

int main()
{
 hs;
 f(N)
  tree[i]=0;
 ll n,q;
 cin>>n>>q;
 ll a[n];
 f(n)
  cin>>a[i];
 char ch[q];
 ll l[q],r[q];
 f(q)
 {
  cin>>ch[i]>>l[i]>>r[i];
  if(ch[i]=='q')
        l[i]--,r[i]--;
  else
    l[i]--;
 }
 build(a,0,0,n-1);
 f(q)
 {
  if(ch[i]=='u')
    update(a,0,0,n-1,l[i],r[i]);
  else
  {
   ll ans=query(a,0,0,n-1,l[i],r[i]);
   cout<<ans<<endl;
  }
 }
 return 0;
}
