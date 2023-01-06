#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  n*=2;
  string s;
  cin>>s;
  vector<int>b;
  int cur=1,cnt=0;
  for(int i=0;i<n;++i)
  {
    if(s[i]=='1')++cnt;
  }
  if(cnt&1)
  {
    cout<<-1<<'\n';
    return;
  }
  for(int i=0;i<n;i+=2)
  {
    if(s[i]==s[i+1])continue;
    int bef=s[i]-'0',aft=s[i+1]-'0';
    if(bef==cur)
    {
        b.push_back(i+1);
    }
    else
    {
        b.push_back(i+2);
    }
    cur^=1;
  }
  cout<<b.size()<<' ';
  if(b.size())
  {
    for(auto& k:b)cout<<k<<" ";
    cout<<'\n';
  }
  for(int i=0;i<n;i+=2)
  {
    cout<<i+1<<' ';
  }
  cout<<'\n';
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