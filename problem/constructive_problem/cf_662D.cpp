#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  for(int i=0;i<n;++i){
    string s;
    cin>>s;
    s=s.substr(4);
    int num=stoi(s);
    int base=10,tmp=0;
    for(int i=1;i<s.size();++i){
        tmp+=base;
        base*=10;
    }
    while(1989+tmp>num)
        num+=base;
    cout<<num<<'\n';
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