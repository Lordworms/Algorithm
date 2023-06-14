#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  cin>>n;
  vector<int>a(n+1);
  map<int,int>mp;
  for(int i=1;i<=n;++i){
    cin>>a[i];
    mp[a[i]]++;
  }
  sort(a.begin()+1,a.end());
  int ans=mp[0];
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){//start from the initial two elements
      if((i!=j)&&(a[i]!=0||a[j]!=0)){
        vector<int>cur;
        int cur1=a[i],cur2=a[j],cur_ans=2;
        mp[a[i]]--;
        mp[a[j]]--;
        cur.push_back(cur1);
        cur.push_back(cur2);
        while(1){
          if(mp[cur1+cur2]){
            mp[cur1+cur2]--;
            cur.push_back(cur1+cur2);
            swap(cur1,cur2);
            cur2=cur1+cur2;
            ++cur_ans;
          }else break;
        }
        ans=max(ans,cur_ans);
        for(int v:cur){
          mp[v]++;
        }
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