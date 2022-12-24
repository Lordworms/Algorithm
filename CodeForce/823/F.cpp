#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define lb(x) x&-x
const int MAXN=5e3+10;
const int LIM=1e9;
void solve()
{
  int n,k;
  cin>>n>>k;
  vector<int>a(n+1),pos(MAXN);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
    a[i]--;
    pos[a[i]]=i;
  }
  vector<int>tree(MAXN,0);
  auto add=[&](int x,int v)
  {
   for(;x<MAXN;x|=x+1)tree[x]+=v;
  };
  auto sum=[&](int r)
  {
    int ans = 0;
    for(; r >= 0; r = (r & r + 1) - 1)
    ans += tree[r];
    return ans;
  };
  // x is the actual used number
  auto get=[&](int p,int mask,int x)
  {
    int ans=0;
    for(int i=0;i<k;++i)
    {
      if((mask&(1<<i))&&pos[x]<pos[p+i+1])++ans;//如果当前已经使用了p+i+1并且x在a中的位置小于arr[p+i+1]
    }
    ans+=sum(MAXN-1)-sum(pos[x]);//这部分是pos[i]>pos[x]的数
    return ans;
  };
  vector dp(n+1,vector<int>(1<<k,LIM));//dp[i][j]表示当前最小未使用为a[i],i-i+k的使用情况为j的时候的最少的逆序对
  dp[0][0]=0;
  for(int p=0;p<n;++p)
  {
    for(int mask=0;mask<(1<<(min(k,n-p-1)));++mask)//枚举之后的情况
    {
      for(int i=0;i<min(k,n-p-1);++i)
      {
        if((mask&(1<<i))==0)
        {
          dp[p][mask+(1<<i)]=min(dp[p][mask+(1<<i)],dp[p][mask]+get(p,mask,p+1+i));//此时的逆序对由位置小于p的元素构成
        }
      }
      int pp=p,maskk=mask;
      pp++;
      while(maskk%2)
      {
        ++pp;maskk/=2;
      }
      maskk/=2;//right move
      dp[pp][maskk]=min(dp[pp][maskk],dp[p][mask]+get(p,mask,p));//
    }
     add(pos[p],1);//a[pos[p]]已经被使用
  }
  cout<<dp[n][0]<<'\n';
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  solve();
  return 0;
}