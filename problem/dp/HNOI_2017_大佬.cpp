#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int MAXN=1e2+10,LIM=1e8;
int maxD=-1;
int dp[MAXN][MAXN];
int a[MAXN],w[MAXN];
int m,n,mc;
struct node{
    int d,l,f;
    node(int _d=0,int _l=0,int _f=0)
    {
        d=_d,l=_l,f=_f;
    }
    bool operator <(const node& b)const{
        if(f==b.f&&d==b.d)return l<b.l;
        else if(f==b.f)return d>b.d;//这个时间是怼大佬所用的时间，而不是时间点,所以肯定要按大的优先级低来弄不然f1+f2+maxd-d1-d2就不是递增的了
        return f<b.f;
    }
    bool operator ==(const node& b)const{//不能写成=
        return d==b.d&&l==b.l&&f==b.f;
    }
};
node q[MAXN<<15],t;
int head,tail;
pi v;
map<pi,bool>mp;
void bfs()
{
    t=node(1,0,1);
    head=tail=1;
    q[tail]=t;
    mp[pi(0,1)]=1;
    while(head<=tail)
    {
        t=q[head++];
        if(t.d>=maxD)continue;
        if(mp[v=pi(t.l+1,t.f)]==0)//增加l
        {
            mp[v]=1;
            q[++tail]=node(t.d+1,t.l+1,t.f);
        }
        if(t.l>1&&1LL*t.l*t.f<=LIM&&mp[v=pi(t.l,t.l*t.f)]==0)
        {
            mp[v]=1;
            q[++tail]=node(t.d+1,t.l,t.l*t.f);
        }
    }

}
void init()
{
    memset(dp,-1,sizeof(dp));
    dp[0][0]=mc;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(dp[i-1][j]-a[i]>=0)//第一种，今天做水题
            {
                dp[i][j]=max(dp[i][j],min(mc,dp[i-1][j]-a[i]+w[i]));
            }
            if(j&&dp[i-1][j-1]>=0)//第二种，今天空时间来干大佬
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]-a[i]);
            }
            if(dp[i][j]>=0)maxD=max(maxD,j);
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m>>mc;
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=n;++i)cin>>w[i];
  init();
  int k;
  bfs();
  sort(q+1,q+tail+1);
  for(int h=0;h<m;++h)
  {
    cin>>k;
    if(k<=maxD)
    {
        cout<<1<<endl;
        continue;
    }  
    int r; 
    for(int i=1;i<=tail;++i)
    {
        if(q[i].f<=k&&q[i].f+maxD-q[i].d>=k)
        {
            cout<<1<<endl;
            goto bak;
        }
    }
    r=tail;
    for(int l=1;l<=r;++l)
    {
        while(q[l].f+q[r].f>k)--r;
        if(l<=r&&q[l].f+q[r].f+maxD-q[l].d-q[r].d>=k)
        {
            cout<<1<<endl;
            goto bak;
        }
    }
    cout<<0<<endl;
    
    bak:1;
  }
  return 0;
}