/*
    CDQ分治类似于动态规划,用来处理以下的问题：
        1.解决和点对有关的问题。
        2.1D 动态规划的优化与转移。
        3.通过 CDQ 分治，将一些动态问题转化为静态问题。
    这类问题可以统一划分为：
        给定一个长度为 n 的序列，统计有一些特性的点对(i,j)的数量/找到一对点(ii,jj)使得一些函数的值最大。
    流程如下:
        1.找到点对的中点mid
        3.把所有的点对划分为三类:
            1.1<=i<=mid n>=j>=mid+1
            2.i,j同属于左边
            3.i,j同属于右边
        4.我们把点化成两个部分，然后递归地处理2，3类点
        5.设法处理第一类点
    千万注意数组下标从0开始的时候的排序问题！！！
    注意不能用sort来merge，这样会超市
*/  
#include <bits/stdc++.h>
using namespace std;
struct node{int a,b,c,cnt,ans;};
int LIM,n;
vector<node>arr;
vector<node>a2;
vector<int>TREE;
int lowbit(int x){return x&-x;}
int sum(int x){int ans=0;while(x){ans+=TREE[x];x-=lowbit(x);}return ans;}
void add(int t,int x){while(t<=LIM){TREE[t]+=x;t+=lowbit(t);}}
bool cmp1(node a,node b)
{
    if(a.a==b.a)
    {
        if(a.b==b.b)
        {
            return a.c<b.c;
        }
        return a.b<b.b;
    }
    return a.a<b.a;
}
bool cmp2(node a,node b)
{
    if(a.b==b.b)return a.c<b.c;
    else return a.b<b.b;
}
void cdq(int l,int r)
{
    if(l>=r)return;
    int mid=(l+r)>>1;
    cdq(l,mid);
    cdq(mid+1,r);
    sort(a2.begin()+l,a2.begin()+mid+1,cmp2);//注意一哈
    sort(a2.begin()+mid+1,a2.begin()+r+1,cmp2);//注意一哈
    int j=l;
    for(int i=mid+1;i<=r;++i)
    {
        while(a2[j].b<=a2[i].b&&j<=mid)
        {
            add(a2[j].c,a2[j].cnt);
            ++j;
        }
        a2[i].ans+=sum(a2[i].c);
    }
    for(int i=l;i<j;++i)add(a2[i].c,-a2[i].cnt);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>LIM;
  arr.resize(n);
  TREE.resize(LIM+1);
  for(int i=0;i<n;++i)
  {
    cin>>arr[i].a>>arr[i].b>>arr[i].c;
    arr[i].cnt=0;
  }
  int cnt;
  sort(arr.begin(),arr.end(),cmp1);
  for(int i=0;i<n;++i)
  {
    ++cnt;
    if(i==n-1||(arr[i].a!=arr[i+1].a||arr[i].b!=arr[i+1].b||arr[i].c!=arr[i+1].c))
    {
        a2.push_back({arr[i].a,arr[i].b,arr[i].c,cnt,0});
        cnt=0;
    }
  }
  cdq(0,a2.size()-1);
  vector<int>ans(n);
  for(int i=0;i<a2.size();++i)
  {
    ans[a2[i].ans+a2[i].cnt-1]+=a2[i].cnt;
  }
  for(int i=0;i<n;++i)cout<<ans[i]<<endl;
  return 0;
}