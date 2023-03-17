#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m;cin>>n>>m;
  vector<int>a(n+1),t(m+1),r(m+1),st;
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=1;i<=m;++i){
    cin>>t[i]>>r[i];
    while(st.size()&&r[st.back()]<r[i])st.pop_back();
    st.push_back(i);
  }
  vector<int>ans(n+1);
  for(int i=r[st[0]]+1;i<=n;++i)ans[i]=a[i];
  sort(a.begin()+1,a.begin()+1+r[st[0]]);
  r.push_back(0);
  st.push_back(r.size()-1);
  int start=1,ed=r[st[0]];
  for(int i=0;i<st.size()-1;++i){
    for(int j=r[st[i]];j>r[st[i+1]];--j){
        if(t[st[i]]==1){
            ans[j]=a[ed--];
        }else{
            ans[j]=a[start++];
        }
    }
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