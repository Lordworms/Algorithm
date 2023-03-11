#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int INF=1e8;
void solve(){
  int x,y;
  cin>>x>>y;
  int n;cin>>n;
  vector<int>a(n+1),b(a);
  a[n]=x,b[n]=y;
  for(int i=0;i<n;++i){
    cin>>a[i]>>b[i];
  }
  auto calc=[&](int i,int j){
    return abs(a[i]-a[j])*abs(a[i]-a[j])+abs(b[i]-b[j])*abs(b[i]-b[j]);
  };
  vector dis(n+1,vector<int>(n+1));
  for(int i=0;i<=n;++i){
    for(int j=0;j<=n;++j){
        dis[i][j]=calc(i,j);
    }
  }
  vector<int>pre(1<<(n+1));
  vector<int>dp(1<<(n+1),INF);
  dp[0]=0;
  for(int i=0;i<(1<<n);++i){
    if(dp[i]==INF)continue;
    for(int j=0;j<n;++j){
        if(((1<<j)&i)==0){
            for(int k=j;k<n;++k){
                if(((1<<k)&i)==0){
                    int d=dis[j][k]+dis[j][n]+dis[k][n];
                    int nxt=i|(1<<j)|(1<<k);
                    if(dp[nxt]>dp[i]+d){
                        dp[nxt]=dp[i]+d;
                        pre[nxt]=i;
                    }
                }
            }
        break;//just transfer first time
        }
    }
  }
  cout<<dp[(1<<n)-1]<<'\n';
  vector<int>ans;
  for(int i=(1<<n)-1;i!=0;i=pre[i]){
    ans.push_back(0);
    int tmp=pre[i]^i;
    int cnt=0;
    for(int j=0;j<n;++j){
        if((1<<j)&tmp){
            ans.push_back(j+1);
        }
    }
  }
  ans.push_back(0);
  for(int i=ans.size()-1;i>=0;--i){
    cout<<ans[i]<<" \n"[i==0];
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