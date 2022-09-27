#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e5+10;
ll p;
ll TREE[MAXN<<2],mtag[MAXN<<2],atag[MAXN<<2];
ll arr[MAXN];
int n,m;
void push_up(int c)
{
    TREE[c]=(TREE[c<<1]+TREE[c<<1|1])%p;    
}
void plu(int c,int l,int r,ll vm,ll vp)
{
   mtag[c]=(mtag[c]*vm)%p;
   atag[c]=(atag[c]*vm+vp)%p;
   TREE[c]=(TREE[c]*vm+vp*(r-l+1))%p;
}
void push_down(int c,int l,int r)
{
    int mid=(l+r)>>1;
    plu(c<<1,l,mid,mtag[c],atag[c]);
    plu(c<<1|1,mid+1,r,mtag[c],atag[c]);
    mtag[c]=1;
    atag[c]=0;
}
void build(int c,int l,int r)
{
    atag[c]=0;
    mtag[c]=1;
    if(l==r){TREE[c]=arr[l];return;}
    int m=(l+r)>>1;
    build(c<<1,l,m);
    build(c<<1|1,m+1,r);
    push_up(c);
}
void update(int l,int r,int cl,int cr,int c,ll vm,ll vp)
{
    if(l<=cl&&r>=cr)
    {
        plu(c,cl,cr,vm,vp);
        return;
    }
    push_down(c,cl,cr);
    int m=(cl+cr)>>1;
    if(l<=m)update(l,r,cl,m,c<<1,vm,vp);
    if(r>m)update(l,r,m+1,cr,c<<1|1,vm,vp);
    push_up(c);
}
ll sum(int l,int r,int cl,int cr,int c)
{
    if(l<=cl&&r>=cr)return TREE[c];
    ll ans=0;
    int m=(cl+cr)>>1;
    push_down(c,cl,cr);
    if(l<=m)ans=(ans+sum(l,r,cl,m,c<<1))%p;
    if(r>m)ans=(ans+sum(l,r,m+1,cr,c<<1|1))%p;
    return ans%p;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("./P3373_2.in","r",stdin);
  freopen("./1.out","w",stdout);
  cin>>n>>m>>p;
  for(int i=1;i<=n;++i)cin>>arr[i];
  build(1,1,n);
  int p,x,y,k;
  while(m--)
  {
    cin>>p;
    switch (p)
    {
    case 2:{//add
        cin>>x>>y>>k;
        update(x,y,1,n,1,1,k);
        break;
    }
    case 1:{//mul
        cin>>x>>y>>k;
        update(x,y,1,n,1,k,0);
        break;
    }
    case 3:{
        cin>>x>>y;
        cout<<sum(x,y,1,n,1)<<endl;
        break;
    }
    }
  }
  return 0;
}