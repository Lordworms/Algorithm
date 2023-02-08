/*
    括号序列：1.闭括号数量永远小于等于开括号数量，如果cnt<0,那么false
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  string s;cin>>s;
  auto check=[&](string& s)
  {
    int cnt=0;
    for(auto & c:s)
    {
        if(c=='(')++cnt;
        if(c==')')--cnt;
        if(cnt<0)return false;
    }
    return true;
  };
  int n=s.size(),op=n/2,cl=n/2;
  vector<int>pos;
  for(int i=0;i<n;++i)
  {
    if(s[i]=='(')--op;
    if(s[i]==')')--cl;
    if(s[i]=='?')pos.push_back(i);
  }
  for(int i=0;i<pos.size();++i)
  {
    if(i<op)s[pos[i]]='(';
    else s[pos[i]]=')';
  }
  bool flag=true;
  if(op>0&&cl>0)
  {
    swap(s[pos[op-1]],s[pos[op]]);
    if(check(s))flag=false;
  }
  cout<<(flag?"YES":"NO")<<'\n';
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}