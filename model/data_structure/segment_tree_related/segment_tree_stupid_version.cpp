/*
  in:
5 5 38
1 5 4 2 3
2 1 4 1
3 2 5
1 2 4 2
2 3 5 5
3 1 4
  out:
17
2

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100;
struct node{
  int lazy_add=0,lazy_mul=1,val;
}tree[4*MAXN];
int arr[MAXN];
int mod,n,m;
void push_up(int c){tree[c].val=(tree[c<<1].val+tree[c<<1|1].val)%mod;}
void push_down(int c,int cl,int cr)//这里可以看到，cm正好处于c这个节点所管辖的范围的中点，所以我们在做递归的时候也可以参考一哈
{
  int cm=(cl+cr)>>1;
  if(tree[c].lazy_add)//注意加法优先
  {
    tree[c<<1].lazy_add+=tree[c].lazy_add;
    tree[c<<1].val+=(cm-cl+1)*tree[c].lazy_add;
    tree[c<<1|1].lazy_add+=tree[c].lazy_add;
    tree[c<<1|1].val+=(cr-cm)*tree[c].lazy_add;
    tree[c].lazy_add=0;
  }
  if(tree[c].lazy_mul!=1)
  {
    tree[c<<1].lazy_mul*=tree[c].lazy_mul;
    tree[c<<1].val*=tree[c<<1].lazy_mul;
    tree[c<<1|1].lazy_mul*=tree[c].lazy_mul;
    tree[c<<1|1].val*=tree[c<<1|1].lazy_mul;
    tree[c].lazy_mul=1;
  }
  tree[c<<1].val%=mod;
  tree[c<<1|1].val%=mod;
}
void build(int l,int r,int c)
{
  if(l>r)return;
  if(l==r)
  {
    tree[c].val=arr[l];
    return;
  }
  int m=(l+r)>>1;
  build(l,m,c<<1);
  build(m+1,r,c<<1|1);
  push_up(c);
}
void update(int l,int r,int cl,int cr,int c,int w,int m)//支持区间update
{
   if(r<cl||l>cr)return;
   if(l<=cl&&r>=cr)
   {
      tree[c].lazy_mul*=m;
      tree[c].lazy_add+=w;
      tree[c].lazy_mul%=mod;
      tree[c].lazy_add%=mod;
      tree[c].val=(tree[c].val+(cr-cl+1)*w%mod);
      tree[c].val%=mod;
      tree[c].val*=m;
      tree[c].val%=mod;
      return;
   }
   push_down(c,cl,cr);
   int cm=(cl+cr)>>1;
   update(l,r,cl,cm,c<<1,w,m);
   update(l,r,cm+1,cr,c<<1|1,w,m);
   push_up(c);
}
int query(int l,int r,int cl,int cr,int c)
{
  if(l>cr||r<cl)return 0;
  if(l<=cl&&r>=cr)return tree[c].val;
  int ans=0;
  int cm=(cl+cr)>>1;
  push_down(c,cl,cr);
  ans+=query(l,r,cl,cm,c<<1);
  ans+=query(l,r,cm+1,cr,c<<1|1);
  return ans%mod;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m>>mod;
  for(int i=1;i<=n;++i)
  {
    cin>>arr[i];
  }
  int type,x,y,k;
  build(1,n,1);
  while(m--)
  {
    cin>>type;
    switch (type)
    {
    case 1:{//乘
      cin>>x>>y>>k;
      update(x,y,1,n,1,0,k);
    }break;
    case 2:{
      cin>>x>>y>>k;
      update(x,y,1,n,1,k,1);
    }break;
    case 3:{
      cin>>x>>y;
      cout<<query(x,y,1,n,1)<<endl;
    }break;
    }
  }
  return 0;
}