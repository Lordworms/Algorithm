#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e5+10;
ll TREE[4*MAXN],tag[4*MAXN];
int arr[MAXN];
int n,m;
void push_up(int c){TREE[c]=TREE[c<<1]+TREE[c<<1|1];}
void plu(int c,int l,int r,int v)
{
    tag[c]+=v;
    TREE[c]+=(r-l+1)*v;
}
void push_down(int c,int l,int r)
{
    int m=(l+r)>>1;
    plu(c<<1,l,m,tag[c]);
    plu(c<<1|1,m+1,r,tag[c]);
    tag[c]=0;
}
void build(int c,int l,int r)
{
    tag[c]=0;
    if(l==r){TREE[c]=arr[l];return;}
    int m=(l+r)>>1;
    build(c<<1,l,m);
    build(c<<1|1,m+1,r);
    push_up(c);
}
void update(int l,int r,int cl,int cr,int c,int v)
{
    if(l<=cl&&r>=cr)
    {
        TREE[c]+=(cr-cl+1)*v;
        tag[c]+=v;
        return;
    }
    push_down(c,cl,cr);
    int m=(cl+cr)>>1;
    if(l<=m)update(l,r,cl,m,c<<1,v);
    if(r>m)update(l,r,m+1,cr,c<<1|1,v);
    push_up(c);
}
ll sum(int l,int r,int cl,int cr,int c)
{
    if(l<=cl&&r>=cr)return TREE[c];
    ll ans=0;
    int m=(cl+cr)>>1;
    push_down(c,cl,cr);
    if(l<=m)ans+=sum(l,r,cl,m,c<<1);
    if(r>m)ans+=sum(l,r,m+1,cr,c<<1|1);
    return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("./P3372_1.in","r",stdin);
  //freopen("./1.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;++i)cin>>arr[i];
  build(1,1,n);
  int p,x,y,k;
  while(m--)
  {
    cin>>p;
    switch (p)
    {
    case 1:{
        cin>>x>>y>>k;
        update(x,y,1,n,1,k);
        break;
    }
    case 2:{
        cin>>x>>y;
        cout<<sum(x,y,1,n,1)<<endl;
        break;
    }
    }
  }
  return 0;
}