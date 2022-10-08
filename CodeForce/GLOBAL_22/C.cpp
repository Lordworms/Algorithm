#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int dp[101][101][2][2];
int dfs(int odd,int even,int st,int t)//x:current status of alice whether have odd sum or even sum
{
    if(dp[odd][even][st][t]!=-1)
    {
        return dp[odd][even][st][t];
    }
    int& res=dp[odd][even][st][t];
    res=0;
    if(!odd&&!even)
    {
        res=!st^t;
    }
    else
    {
        if(even)res|=!dfs(odd,even-1,st,!t);
        if(odd)res|=!dfs(odd-1,even,st^!t,!t);
    }
    return res;
}
void solve()
{
    int n,x;
    cin>>n;
    int odd=0,even;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        if(x%2)odd++;
    }    
    if(dfs(odd,n-odd,0,0))cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  memset(dp,-1,sizeof(dp));
  while(t--)
  {
    solve();
  }
  return 0;
}