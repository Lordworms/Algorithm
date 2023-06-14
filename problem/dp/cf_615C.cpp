#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s,t;
  cin>>s>>t;
  int lenp=s.size(),leno=t.size();
  vector<vector<int>>ans;
  bool matched=false;
  for(int j=0;j<t.size();++j){//origin
    int cur_len=-1;
    matched=false;
    ans.push_back(vector<int>(2));
    for(int i=0;i<s.size();++i){//pattern
        if(s[i]==t[j]){
            matched=true;
            int l=i,r=l;
            int k=0;
            for(int k=1;i+k<s.size()&&j+k<t.size();++k){
                if(s[i+k]==t[j+k])++r;
                else break;
            }
            if(r-l+1>cur_len){
                cur_len=r-l;
                ans.back()[0]=l;
                ans.back()[1]=r;
            }
            l=r=i;
            k=0;
            for(int k=1;i-k>=0&&j+k<t.size();++k){
                if(s[i-k]==t[j+k])--l;
                else break;
            }
            if(r-l+1>cur_len){
                cur_len=r-l;
                ans.back()[0]=r;
                ans.back()[1]=l;
            }
        }
    }
    if(!matched){
        break;
    }
    j+=cur_len;
  }
  if(!matched){
    cout<<-1<<'\n';
  }else{
    cout<<ans.size()<<'\n';
    for(auto k:ans){
        cout<<k[0]+1<<' '<<k[1]+1<<'\n';
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