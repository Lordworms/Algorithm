#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;cin>>n;
  vector<int>a(n+1);
  for(int i=0;i<n;++i)cin>>a[i];
  int maxx=*max_element(a.begin(),a.end());
  rotate(a.begin(),max_element(a.begin(),a.end()),a.end());
  a.push_back(a[0]);
  vector<int>L(n+1),R(n+1),cnt(n+1);
  ll ans=0;
  vector<int>st;
  for(int i=n-1;i>=0;--i){
    while(st.size()&&a[st.back()]<=a[i]){
        if(a[st.back()]==a[i]&&a[st.back()]!=maxx)cnt[i]=cnt[st.back()]+1;
        st.pop_back();
    }
    if(st.empty()){
        R[i]=n;
    }else{
        R[i]=st.back();
    }
    st.push_back(i);
  }
  st.clear();
  for(int i=0;i<n;++i){
    while(st.size()&&a[st.back()]<=a[i]){
        st.pop_back();
    }
    if(st.empty()){
        L[i]=-1;
    }else{
        L[i]=st.back();
    }
    st.push_back(i);
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