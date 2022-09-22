#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+100;
const int maxm=5e4+100;
int n,m;
int b[maxn],c[maxn];
int t[maxn];
ll ans;
struct node
{
    int x,y,z;//x:删除的时间 y:pos z:值
    int f,g;
} a[maxn],A[maxn];

inline void xg(int x,int y)
{
    while (x<=n)
    {
        t[x]+=y;
        x+=x&(-x);
    }
}
inline int qsum(int x)
{
    int sum=0;
    while (x)
    {
        sum+=t[x];
        x-=x&(-x);
    }
    return sum;
}

bool cmp(node aa,node bb)//按照位置排序
{
    return aa.y<bb.y;
}
bool cmp1(node aa,node bb)//按照删除时间排
{
    return aa.x>bb.x;
}
bool cmp2(node aa,node bb)
{
    return aa.x<bb.x;
}
void cdq(int x,int y)
{
    if (x==y) return;
    int mid=(x+y)>>1;
    cdq(x,mid);cdq(mid+1,y);
    int l=x,r=mid+1,p=0;
    while (r<=y)//统答案
    {
        while (l<=mid&&a[l].z>a[r].z) {xg(a[l].y,1);l++;}
        a[r].f+=qsum(a[r].y);
        r++;
    }
    for (int i=x;i<l;i++) xg(a[i].y,-1);

    l=x,r=mid+1,p=x-1;//归并
    while (l<=mid&&r<=y)
    {
        if (a[l].z>a[r].z) A[++p]=a[l++]; else A[++p]=a[r++];
    }
    while (l<=mid) A[++p]=a[l++];
    while (r<=y) A[++p]=a[r++];
    for (int i=x;i<=y;i++) a[i]=A[i];
}
void CDQ(int x,int y)
{
    if (x==y) return;
    int mid=(x+y)>>1;
    CDQ(x,mid);CDQ(mid+1,y);
    int l=x,r=mid+1,p=0;
    while (r<=y)
    {
        while (l<=mid&&a[l].y>a[r].y) {xg(a[l].z,1);l++;}
        a[r].g+=qsum(a[r].z);
        r++;
    }
    for (int i=x;i<l;i++) xg(a[i].z,-1);//memset太慢了，不如一个个清

    l=x,r=mid+1,p=x-1;//按照y的大小合并
    while (l<=mid&&r<=y)
    {
        if (a[l].y>a[r].y) A[++p]=a[l++]; else A[++p]=a[r++];
    }
    while (l<=mid) A[++p]=a[l++];
    while (r<=y) A[++p]=a[r++];
    for (int i=x;i<=y;i++) a[i]=A[i];
}
int main()
{
    cin>>n>>m;
    int x;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        a[x].y=i;
        a[x].z=x;
        ans+=i-1-qsum(x);
        xg(x,1);
    }
    memset(t,0,sizeof(t));
    for (int i=1;i<=m;i++)
    {
        cin>>x;
        a[x].x=i;
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1,j=m+1;i<=n;i++)
    {
        if (a[i].x==0) a[i].x=j++;
    }
    sort(a+1,a+n+1,cmp1);
    cdq(1,n);//求出f[i]
    sort(a+1,a+n+1,cmp1);
    CDQ(1,n);//求出g[i]
    sort(a+1,a+n+1,cmp2);
    for (int i=1;i<=m;i++)
    {
        cout<<ans<<endl;
        ans=ans-(ll)a[i].f-(ll)a[i].g;
    }
    return 0;
}