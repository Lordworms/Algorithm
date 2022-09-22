/*
    用vector来排序的时候记住
    [INF,1,2,3,4,5,6,7]
    用分治(1,7)
    1.排区间[1,mid]=[1,4]
    sort(arr.begin()+l,arr.begin()+mid+1)<=一定注意这个mid+1
    sort的时候尾端一定别忘了+1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+100;
int n,m;
struct node{int x,y,z,f,q;}arr[MAXN],A[MAXN];
bool cmp(node a,node b){return a.y<b.y;}
bool cmp1(node a,node b){return a.x>b.x;}
bool cmp2(node a,node b){return a.x<b.x;}
int TREE[MAXN];
int lowbit(int x){return x&-x;}
void add(int t,int x){
    while(t<=n)
    {
        TREE[t]+=x;
        t+=lowbit(t);
    }
}
int sum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=TREE[x];
        x-=lowbit(x);
    }
    return ans;
}
void cdq1(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    cdq1(l,mid),cdq1(mid+1,r);
    int j=l,i=mid+1,p=0;
    while(i<=r)
    {
        while(j<=mid&&arr[i].z<arr[j].z)
        {
            add(arr[j].y,1);
            ++j;
        }
        arr[i].f+=sum(arr[i].y);
        ++i;
    }
    for(i=l;i<j;++i)add(arr[i].y,-1);
    i=l,j=mid+1,p=l;
    while(i<=mid&&j<=r)
    {
        if(arr[i].z>arr[j].z)A[p++]=arr[i++];
        else A[p++]=arr[j++];
    }
    while(i<=mid)A[p++]=arr[i++];
    while(j<=r)A[p++]=arr[j++];
    for(i=l;i<=r;++i)arr[i]=A[i];
}
void cdq2(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    cdq2(l,mid),cdq2(mid+1,r);
    int j=l,i=mid+1,p=0;
    while(i<=r)
    {
        while(j<=mid&&arr[i].y<arr[j].y)
        {
            add(arr[j].z,1);
            ++j;
        }
        arr[i].q+=sum(arr[i].z);
        ++i;
    }
    for(i=l;i<j;++i)add(arr[i].z,-1);
    i=l,j=mid+1,p=l;
    while(i<=mid&&j<=r)
    {
        if(arr[i].y>arr[j].y)A[p++]=arr[i++];
        else A[p++]=arr[j++];
    }
    while(i<=mid)A[p++]=arr[i++];
    while(j<=r)A[p++]=arr[j++];
    for(i=l;i<=r;++i)arr[i]=A[i];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  int x;
  ll ans=0;
  for(int i=1;i<=n;++i)
  {
    cin>>x;
    arr[x].y=i;
    arr[x].z=x;
    ans+=i-1-sum(x);
    add(x,1);
  }
  memset(TREE,0,sizeof(TREE));
  for(int i=1;i<=m;++i)
  {
    cin>>x;
    arr[x].x=i;
  }
  sort(arr+1,arr+1+n,cmp);
  for(int i=1,j=m+1;i<=n;++i)
  {
    if(!arr[i].x)arr[i].x=j++;
  }
  sort(arr+1,arr+n+1,cmp1);
  cdq1(1,n);
  sort(arr+1,arr+n+1,cmp1);
  cdq2(1,n);
  sort(arr+1,arr+n+1,cmp2);
  for(int i=1;i<=m;++i)
  {
    cout<<ans<<endl;
    ans-=(arr[i].f+arr[i].q);
  }
  return 0;
}