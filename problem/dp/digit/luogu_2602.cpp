#include <bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int>dig;
const int N=15;
ll dp[N][N][2][2];
ll dfs(int pos,ll sum,bool zero,bool flag,int d)
{
    if(pos==0)return sum;
    if(~dp[pos][sum][zero][flag])return dp[pos][sum][zero][flag];
    ll &res=dp[pos][sum][zero][flag];
	res=0;
    int lim=flag?dig[pos]:9;
    for(int i=0;i<=lim;++i)
    {
        res+=dfs(pos-1,sum+((i==d)&&!(zero&&!i)),zero&&!i,flag&&i==lim,d);
    }
    return res;
}
void trans(ll num)
{
    memset(dp,-1,sizeof(dp));
    dig.clear();
    dig.push_back(0);
    while(num)
    {
        dig.push_back(num%10);
        num/=10;
    }
}
void solve()
{
  ll l,r;
  cin>>l>>r;
  for(int i=0;i<10;++i)
  {
    ll rans,lans;
    trans(l-1);
    lans=dfs(dig.size()-1,0,1,1,i);//第一位只能枚举到dig[pos];
    trans(r);
    rans=dfs(dig.size()-1,0ll,1,1,i);
    cout<<rans-lans<<' ';
  }
  cout<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}