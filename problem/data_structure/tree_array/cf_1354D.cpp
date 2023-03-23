#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int N=1e6+10;
#define lowbit(x) x&-x
void solve(){
  int n,k;cin>>n>>k;
  vector<int>tree(n+1);
  auto add=[&](int x,int v){
    while(x<=n){
        tree[x]+=v;
        x+=lowbit(x);
    }
  };
  auto query=[&](int x){
    ll ans=0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
  };
  auto getk=[&](int x){
    int l=1,r=n;
    while(l<=r){
        int m=(l+r)>>1;
        int tmp=query(m);
        if(tmp<x){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return l;
  };
  for(int i=0;i<n;++i){
    int x;cin>>x;
    add(x,1);
  }
  for(int i=0;i<k;++i){
    int x;cin>>x;
    if(x>0){
        add(x,1);
    }else{
        int qn=query(n);
        int id=getk(-x);
        add(id,-1);
    }
  }
  if(query(n)==0){
    cout<<0<<'\n';
  }else{
    cout<<getk(1)<<'\n';
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