/*
    for xor problem, we need to consider from high position to low position
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=3e5*31;
int trie[N][2];
int f[N][2];//f[i][j] stores the answer that the trie id is i and the corresbonding bit is j
int cnt=0;
int add()
{
    ++cnt;
    trie[cnt][0]=trie[cnt][1]=0;
    f[cnt][0]=f[cnt][1]=0;
    return cnt;
}
void solve()
{
  int n;
  cin>>n;
  cnt=0;
  vector<int>a(n);
  vector<int>dp(n);
  for(int i=0;i<n;++i)cin>>a[i];
  add();
  int now;
  for(int i=0;i<n;++i)
  {
    int x=a[i]^i;
    now=1;
    for(int j=29;j>=0;--j)
    {
        int v=x>>j&1;
        dp[i]=max(dp[i],f[trie[now][!v]][i>>j&1]);//calculate 
        now=trie[now][v];
        if(!now)
        {
            break;
        }
    }
    dp[i]++;
    now=1;
    for(int j=29;j>=0;--j)
    {
        int v=x>>j&1;
        if(!trie[now][v])
        {
            trie[now][v]=add();
        }
        now=trie[now][v];
        f[now][a[i]>>j&1]=max(f[now][a[i]>>j&1],dp[i]);
    }
  }
  cout<<*max_element(dp.begin(),dp.end())<<'\n';
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
    solve();
  }
  return 0;
}