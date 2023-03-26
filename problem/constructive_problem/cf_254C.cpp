/*
  首先找到s中出现次数大于t中出现次数的值，这些字符是需要更改的,然后我们遍历对应的cnt数组，如果j<x并且又可以进行替换，那么直接换，否则
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  string s,t;
  cin>>s>>t;
  //we need to find those places that cnt1[s[i]]>cnt2[s[i]],then transform them
  vector<int>cnt1(26),cnt2(26);
  for(int i=0;i<s.size();++i){
    cnt1[s[i]-'A']++;
    cnt2[t[i]-'A']++;
  }
  int ans=0;
  for(int i=0;i<s.size();++i){
    int x=s[i]-'A';
    if(cnt1[x]>cnt2[x]){
      for(int j=0;j<26;++j){
        if(cnt1[j]<cnt2[j]){
          if(j<x||!cnt2[x]){
            cnt2[j]--;
            s[i]=j+'A';
            ++ans;
          }else{
            cnt2[x]--;
          }
          break;
        }
      }
      cnt1[x]--;//subtract it in s
    }
  }
  cout<<ans<<'\n'<<s<<'\n';
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}