#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,k;
  cin>>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;++i)cin>>a[i];
  double sum=0;
  for(int i=1;i<=n;++i)sum+=1.0*i;
  function<double(int)>dfs=[&](int num){
    if(num==0){
        double total=0.0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(a[i]>a[j]){
                    total+=1.0;
                }
            }
        }
        return total;
    }
    double cur=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<=n;++j){
            reverse(a.begin()+i,a.begin()+j);
            cur+=dfs(num-1);
            reverse(a.begin()+i,a.begin()+j);
        }
    }
    return cur/sum;
  };
  cout.precision(10);
  cout<<dfs(k)<<'\n';
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