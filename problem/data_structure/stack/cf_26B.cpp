#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s;
  cin>>s;
  vector<char>st;
  int last_len=0;
  int ans=0;
  for(int i=0;i<s.size();++i){
    if(s[i]=='('){
        st.push_back(s[i]);
    }else{
        while(st.size()&&st.back()==')')st.pop_back();
        if(st.size()){
            last_len+=2;
            ans=max(ans,last_len);
            st.pop_back();
        }
    }
  }
  cout<<ans<<'\n';
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