#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n;
  string s;
  cin>>n>>s;
  int k;cin>>k;
  vector tree(n<<7,vector<int>(26));//2^7
  vector<int>id(n<<7);
  int cnt=0;
  auto insert=[&](string ss,int now){
    int cur=0;
    for(int i=0;i<ss.size();++i){
        int index=ss[i]>='A'&&ss[i]<='Z'?ss[i]-'A':ss[i]-'a';
        if(!tree[cur][index]){
            tree[cur][index]=++cnt;
        }
        cur=tree[cur][index];
        if(i==s.size()-1)tree[cur][index]++;
    }
    id[cur]=now;
  };
  vector<string>dic(k+1);
  for(int i=1;i<=k;++i){
    cin>>dic[i];
    insert(dic[i],i);
  }
  vector<int>dp(n+1);
  for(int i=0;i<n;++i){
    int cur=0;
    for(int j=i;j>=0;--j){
        int index=s[j]>='A'&&s[j]<='Z'?s[j]-'A':s[j]-'a';
        if(!tree[cur][index])break;
        cur=tree[cur][index];
        if(id[cur]&&(j==0||dp[j-1])){
            dp[i]=id[cur];
            break;
        }  
    }
  }
  int status=n-1;
  vector<string>ans;
  while(status>=0&&dp[status]){
    ans.push_back(dic[dp[status]]);
    status-=dic[dp[status]].size();
  }
  for(int i=ans.size()-1;i>=0;--i){
    cout<<ans[i]<<" \n"[i==0];
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