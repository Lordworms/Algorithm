/*
    it is better to add or sub number to smallar number
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<ll,int>;
void solve(){
  int n,k,x;
  cin>>n>>k>>x;
  vector<ll>a(n+1);
  bool sign=false;
  set<pii>st;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    if(a[i]<0){
        sign=!sign;
    }
    st.insert({abs(a[i]),i});
  }
  for(int i=1;i<=k;++i){
    auto id=st.begin()->second;
    st.erase(st.begin());
    if(a[id]<0)sign=!sign;
    if(sign){
        a[id]+=x;
    }
    else
    {
        a[id]-=x;
    }
    if(a[id]<0)sign=!sign;
    st.insert({abs(a[id]),id});
  }
  for(int i=1;i<=n;++i){
    cout<<a[i]<<" \n"[i==n];
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