#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int ls[50*MAXN],rs[50*MAXN],rt[50*MAXN],sum[50*MAXN];
int cnt;
int arr[MAXN],a[MAXN];
void build(int &c,int l,int r)
{   
    c=++cnt;
    sum[c]=0;
    if(l==r){return;}
    int m=(l+r)>>1;
    build(ls[c],l,m);
    build(rs[c],m+1,r);
}
void update(int &c,int l,int r,int pre)
{
    c=++cnt;
    ls[c]=ls[pre],rs[c]=rs[pre],sum[c]=sum[pre]+1;
    int m=(l+r)>>1;
    if(l==r)return;
    update(ls[c],l,m,ls[pre]);
    update(rs[c],m+1,r,rs[pre]);
}
int query(int ql,int qr,int l,int r,int k)
{
    if(l==r)return l;
    int x=sum[ls[qr]]-sum[ls[ql]];
    int mid=(l+r)>>1;
    if(x>=k)return query(ls[ql],ls[qr],l,mid,k);
    else return query(rs[qr],rs[ql],mid+1,r,k-x);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}