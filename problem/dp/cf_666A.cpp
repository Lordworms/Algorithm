#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  string s;
  cin>>s;
  int n=s.size();
  vector<vector<int>>dp(n+1,vector<int>(2));
  s+='0';
  dp[n-3][1]=dp[n-2][0]=1;
  //dp[i][0]表示子字符串[i:i+1]有效
  //dp[i][1]表示子字符串[i:i+2]有效
  for(int i=n-4;i>=5;--i)
  {
    if(dp[i+2][1]||dp[i+2][0]&&(s[i]!=s[i+2]||s[i+1]!=s[i+3]))
    {
        dp[i][0]=1;
    }
    if(dp[i+3][0]||dp[i+3][1]&&(s[i]!=s[i+3]||s[i+1]!=s[i+4]||s[i+2]!=s[i+5]))
    {
        dp[i][1]=1;
    }
  }
  set<string>st;
  for(int i=5;i<n;++i)
  {
    string tmp;
    if(dp[i][0])
    {
        tmp+=s[i];
        tmp+=s[i+1];
        st.insert(tmp);
    }
    tmp="";
    if(dp[i][1])
    {
        tmp+=s[i];
        tmp+=s[i+1];
        tmp+=s[i+2];
        st.insert(tmp);
    }
  }
  cout<<st.size()<<'\n';
  for(auto str:st)
  {
    cout<<str<<'\n';
  }
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