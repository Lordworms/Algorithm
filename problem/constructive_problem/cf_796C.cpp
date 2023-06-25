#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  int max_=-INF;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    max_=max(a[i],max_);
  }
  vector<vector<int>>E(n+1);
  for(int i=1;i<=n-1;++i){
    int u,v;
    cin>>u>>v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<pii>info(n+1);
  int max_cnt=0,max_minus_cnt=0;
  for(int i=1;i<=n;++i){
    if(a[i]==max_){
        ++max_cnt;
    }
    if(a[i]==max_-1){
        ++max_minus_cnt;
    }
  }
  for(int i=1;i<=n;++i){
    int m_c=0,m1_c=0;
    if(a[i]==max_){
        ++m_c;
    }if(a[i]==max_-1){
        ++m1_c;
    }
    for(int v:E[i]){
        if(a[v]==max_){
            ++m_c;
        }
        if(a[v]==max_-1){
            ++m1_c;
        }
    }
    info[i]=make_pair(m_c,m1_c);
  }
  int r;
  for(int i=1;i<=n;++i){
    if(a[i]==max_){
        r=i;
        break;
    }
  }
  if(max_cnt==1){
    if(info[r].second==max_minus_cnt){
        cout<<max_<<'\n';
        return;
    }
  }
  for(int i=1;i<=n;++i){
    if(info[i].first==max_cnt){
        cout<<max_+1;
        return;
    }
  }
  cout<<max_+2<<'\n';
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