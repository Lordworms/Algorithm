#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    unordered_map<char,vector<string>>mp;
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i)
    {
        if(mp[s[i]].empty())mp[s[i]].push_back("");
        mp[s[i]][0].push_back(s[i]);
    }
    for(auto& k:mp)k.second.push_back(k.second[0]);
    string ans;
    for(auto& k:mp)
    {
        ans.insert(ans.size(),k.second[1]);
        ans.insert(0,k.second[0]);
    }
    cout<<ans<<'\n';
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}