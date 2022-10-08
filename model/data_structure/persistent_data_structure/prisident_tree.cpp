#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int arr[MAXN];
int ls[40*MAXN],rs[40*MAXN],rt[40*MAXN],val[40*MAXN];
int cnt;
void build(int &c,int l,int r)
{
    c=++cnt;
    if(l==r){val[c]=arr[l];return;}
    int m=(l+r)>>1;
    build(ls[c],l,m);
    build(rs[c],m+1,r);
}
void update(int &c,int pre,int l,int r,int pos,int v)//把pre版本的pos位置的值改为v
{
    c=++cnt,ls[c]=ls[pre],rs[c]=rs[pre],val[c]=val[pre];
    if(l==r){val[c]=v;return;}
    int mid=(l+r)>>1;
    if(pos<=mid)update(ls[c],ls[pre],l,mid,pos,v);
    else update(rs[c],rs[pre],mid+1,r,pos,v);
}
int query(int o,int l,int r,int q)
{
    if(l==r)return val[o];
    int m=(l+r)>>1;
    if(q<=m)return query(ls[o],l,m,q);
    else return query(rs[o],m+1,r,q);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("./in.txt","r",stdin);
  freopen("./out.txt","w",stdout);
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;++i)cin>>arr[i];
  build(rt[0],1,n);
  int version,opt,pos,v;
  for(int i=1;i<=m;++i)
  {
    cin>>version;
    cin>>opt;
    switch (opt)
    {
    case 1:{
        cin>>pos>>v;
        update(rt[i],rt[version],1,n,pos,v);
        break;
    }
    case 2:{
        cin>>pos;
        cout<<query(rt[version],1,n,pos)<<endl;
        rt[i]=rt[version];
        break;
    }
    }
  }
  return 0;
}