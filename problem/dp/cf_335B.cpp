#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s;
  cin>>s;
  int n=s.size();
  s=' '+s;
  if(n>=2600){
    vector<int>cnt(26);
    for(int i=1;i<=n;++i){
        cnt[s[i]-'a']++;
    }
    for(int i=0;i<26;++i){
        if(cnt[i]>=100){
            for(int j=0;j<100;++j){
                cout<<(char)('a'+i);
            }
            return;
        }
    }
  }
  vector dp(n+2,vector<int>(n+2));
  for(int i=n;i>=1;--i){
    dp[i][i]=1;
    for(int j=i+1;j<=n;++j){
        if(s[i]==s[j]){
            dp[i][j]=dp[i+1][j-1]+2;
        }else{
            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        }
    }
  }
  int l=1,r=n;
  vector<char>ans;
  while(l<=r){
    if(s[l]==s[r]){
        ans.push_back(s[l]);
        ++l,--r;
    }else if(dp[l+1][r]>dp[l][r-1]){
        ++l;
    }else{
        --r;
    }
  }
  for(int i=0;i<min((int)ans.size(),50);++i){
    cout<<ans[i];
  }
  if(min(dp[1][n],100)%2==0)cout<<ans[min((int)ans.size()-1,50)];
  for(int i=min((int)ans.size()-2,49);i>=0;--i){
    cout<<ans[i];
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}