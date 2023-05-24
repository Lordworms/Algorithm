#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=100+10;
double dp[N][N][N];
void solve(){
  int r,s,p;
  cin>>r>>s>>p;
  dp[r][s][p]=1.0;
  for(int i=r;i>=0;--i){
    for(int j=s;j>=0;--j){
        for(int k=p;k>=0;--k){
            if(i){// kill sissor
                dp[i][j][k]+=dp[i][j+1][k]*(j+1)*i/((j+1)*k+(j+1)*i+i*k);
            }
            if(j){//kill paper
                dp[i][j][k]+=dp[i][j][k+1]*(k+1)*j/((k+1)*i+(k+1)*j+j*i);
            }
            if(k){//kill rock
                dp[i][j][k]+=dp[i+1][j][k]*(i+1)*k/((i+1)*j+(i+1)*k+j*k);
            }
        }
    }
  }
  double ans1=0,ans2=0,ans3=0;
  for(int i=1;i<=r;++i)ans1+=dp[i][0][0];
  for(int i=1;i<=s;++i)ans2+=dp[0][i][0];
  for(int i=1;i<=p;++i)ans3+=dp[0][0][i];
  cout.precision(11);
  cout<<ans1<<' '<<ans2<<' '<<ans3<<'\n';
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