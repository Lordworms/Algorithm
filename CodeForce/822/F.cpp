#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=65;
ll dp[64][MAXN][2][2];
ll n,m;
ll dfs(int x,int tail,bool odd,bool flag)//flag表示上一位也取到最后一个的值了
{
    if(x==-1)
    {
        return odd==1 &&!flag;
    }
    if(~dp[x][tail][odd][flag])return dp[x][tail][odd][flag];
    ll &res=dp[x][tail][odd][flag];res=0;
    int bit=n>>x&1,lim=flag?(m>>x&1):1;
    for(int i=0;i<=lim;++i)
    {
        int w=bit+i;
        if(!w)
            res+=dfs(x-1,0,odd,flag&&(i==lim));
        else if(w==1)
        {
            res+=dfs(x-1,tail+1,odd^1^i,flag&&(i==lim));
        }
        else if(w==2)
        {
            res+=dfs(x-1,0,odd^((tail-1)&1)^1,flag&&(i==lim));
        }
    }
    return res;
}
void solve()
{
  cin>>n>>m;
  cout<<dfs(63,0,0,1)<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    memset(dp,-1,sizeof(dp));
    solve();
  }    
  return 0;
}