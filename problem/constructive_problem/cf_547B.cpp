#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  vector<int>l(n+1),r(n+1);
  vector<int>st;
  for(int i=1;i<=n;++i){
    while(st.size()&&a[st.back()]>=a[i])st.pop_back();
    if(!st.size()){
        l[i]=1;
    }else{
        l[i]=st.back()+1;
    }
    st.push_back(i);
  }
  st.clear();
  for(int i=n;i>=1;--i){
    while(st.size()&&a[st.back()]>=a[i])st.pop_back();
    if(!st.size()){
        r[i]=n;
    }else{
        r[i]=st.back()-1;
    }
    st.push_back(i);
  }
  vector<int>ans(n+1);
  for(int i=1;i<=n;++i){
    ans[r[i]-l[i]+1]=max(ans[r[i]-l[i]+1],a[i]);
  }
  for(int i=n-1;i>=1;--i){
    ans[i]=max(ans[i+1],ans[i]);
  }
  for(int i=1;i<=n;++i){
    cout<<ans[i]<<" \n"[i==n];
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