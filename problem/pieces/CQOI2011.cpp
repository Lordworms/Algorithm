#include <bits/stdc++.h>
using namespace std;
const int LIM=5e4+10;
struct node{int x=LIM,y,z,f=0,q=0;};
vector<int>TREE(LIM);
vector<node>arr;
int n,m;
int lowbit(int x){return x&-x;}
int sum(int x){int ans=0;while(x){ans+=TREE[x];x-=lowbit(x);}return ans;}
void add(int t,int x){while(t<=LIM){TREE[t]+=x;t+=lowbit(t);}}
bool cmp(node a,node b){return a.y<b.y;}
bool cmp1(node a,node b){return a.x>b.x;}
bool cmp2(node a,node b){return a.x<b.x;}
bool cmp3(node a,node b){return a.z>b.z;}//此种情况对应了找i位置之前的逆序对 
bool cmp4(node a,node b){return a.y>b.y;}//此种情况对应了找i之后的逆序对
//第一次分治，求出对之前的元素的影响,树状数组存z，排序排z，按z降序排列
void cdq1(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    cdq1(l,mid);
    sort(arr.begin()+1+l,arr.begin()+1+mid,cmp3);
    cdq1(mid+1,r);
    sort(arr.begin()+mid+1,arr.begin()+1+r,cmp3);
    int j=l;
    for(int i=mid+1;i<=r;++i)
    {
        while(j<=mid&&arr[i].z<arr[j].z)//值要比前面的小，位置要大
        {
            add(arr[j].y,1);
            ++j;
        }
        arr[i].f+=sum(arr[i].y);
    }
    for(int i=l;i<j;++i)
    {
        add(arr[j].y,-1);
    }
}
//第二次分治求出对后面元素的影响，树状数组存y，排序排y,要求按y降序排列
void cdq2(int l,int r)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    cdq1(l,mid);
    sort(arr.begin()+1+l,arr.begin()+1+mid,cmp4);
    cdq1(mid+1,r);
    sort(arr.begin()+mid+1,arr.begin()+1+r,cmp4);
    int j=l;
    for(int i=mid+1;i<=r;++i)
    {
        while(j<=mid&&arr[i].y<arr[j].y)//位置要比前面的要小，值要大
        {
            add(arr[j].z,1);
            ++j;
        }
        arr[i].q+=sum(arr[i].z);
    }
    for(int i=l;i<j;++i)
    {
        add(arr[j].z,-1);
    }
}
void solve()
{
    cin>>n>>m;
    int x;
    int ans=0;
    arr.resize(n+1);
    for(int i=0;i<n;++i)
    {
        cin>>x;
        arr[x].y=i;
        arr[x].z=x;
        ans+=i-sum(x);
        add(x,1);
    }
    for(int i=0;i<m;++i)
    {
        cin>>x;
        arr[x].x=i;
    }
    sort(arr.begin()+1,arr.begin()+n,cmp1);
    cdq1(1,n);
    sort(arr.begin()+1,arr.end(),cmp1);
    cdq2(1,n);
    sort(arr.begin()+1,arr.begin()+n,cmp2);
    for(int i=1;i<=m;++i)
    {
        cout<<ans<<endl;
        ans-=arr[i].f;
        ans-=arr[i].q;
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}