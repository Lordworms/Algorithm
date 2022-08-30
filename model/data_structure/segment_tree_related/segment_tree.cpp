#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int arr[maxn];
struct node
{
    int l,r,v;
}tree[4*maxn];
void build(int c,int l,int r)
{
    tree[c].l=l,tree[c].r=r;
    if(l==r){tree[c].v=arr[l];return;}
    int m=(l+r)>>1;
    build(c<<1,l,m),build(c<<1|1,m+1,r);
    tree[c].v=tree[c<<1].v+tree[c<<1|1].v;//区间求和
    //tree[c].v=max(tree[c<<1],tree[c<<1|1]);//区间最大值
}
void update(int c,int x,int v)
{
    if(tree[c].l==tree[c].r)
    {
        tree[c].v+=v;//区间加和
        //tree[c].v=v;//区间更新
        return;
    }
    int m=(tree[c].l+tree[c].r)>>1;
    if(x<=m)update(c<<1,x,v);
    else update(c<<1|1,x,v);
    tree[c].v=tree[c<<1].v+tree[c<<1|1].v;
}
//调用方式query(c,start,end)
int query(int c,int l,int r)
{
    if(l<=tree[c].v&&r>=tree[c].r)return tree[c].v;
    int m=(tree[c].l+tree[c].r)>>1;
    int sum=0;
    if(l<=m)sum+=query(c<<1,l,r);
    if(r>m)sum+=query(c<<1|1,l,r);
    return sum;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   return 0;
}
