#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<vector<int>>E(n+1);
  vector<int>val(n+1);
  int r=-1;
  ll sum=0;
  for(int i=1;i<=n;++i){
    int a,t;
    cin>>a>>t;
    sum+=t;
    val[i]=t;
    if(a==0){
        r=i;
    }else{
        E[a].push_back(i);
    }
  }
  if(sum%3){
    cout<<-1<<'\n';
    return;
  }
  int ans1=-1,ans2=-1;
  int part=sum/3;
  function<void(int,int)>dfs=[&](int x,int f){
    for(int& v:E[x]){
        dfs(v,x);
        val[x]+=val[v];
    }
    if(val[x]==part&&x!=r){
        val[x]=0;//clear this value inorder not to influence the next steps
        if(ans1==-1){
            ans1=x;
        }else if(ans2==-1){
            ans2=x;
        }
    }
  };
  dfs(r,-1);
  if(ans1!=-1&&ans2!=-1){
    cout<<ans1<<' '<<ans2<<'\n';
  }else{
    cout<<-1<<'\n';
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