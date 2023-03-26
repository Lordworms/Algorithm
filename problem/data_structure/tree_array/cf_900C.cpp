#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define lowbit(x) x&-x
void solve(){
  int n;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i){
    cin>>a[i];
  }
  vector<int>tree(n+1);
  auto add=[&](int x,int v){
    while(x<=n){
        tree[x]+=v;
        x+=lowbit(x);
    }
  };
  auto sum=[&](int x){
    ll ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
  };
  int maxx=0,ans=-1;
  vector<int>cnt(n+1);
  for(int i=0;i<n;++i){
    maxx=max(a[i],maxx);
    int res=sum(a[i]);
    if(res==i-1){
        cnt[maxx]++;
    }else if(res==i){
        cnt[maxx]--;
    }
    add(a[i],1);
  }
  int ansi=1;
  for(int i=1;i<=n;++i){
    if(cnt[i]>ans){
        ans=cnt[i];
        ansi=i;
    }
  }
  cout<<ansi<<'\n';
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