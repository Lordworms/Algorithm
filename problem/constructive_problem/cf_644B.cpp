#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,b;
  cin>>n>>b;
  deque<ll>q;
  vector<ll>t(n),d(n);
  for(int i=0;i<n;++i){
    cin>>t[i]>>d[i];
  }
  for(int i=0;i<n;++i){
    while(q.size()&&q.front()<=t[i]){
        q.pop_front();
    }
    if(q.empty()){
        q.push_back(t[i]+d[i]);
        cout<<q.front()<<' ';
    }else{
        if(q.size()>b){
            cout<<-1<<" ";
        }else{
            cout<<q.back()+d[i]<<' ';
            q.push_back(q.back()+d[i]);
        }
    }
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