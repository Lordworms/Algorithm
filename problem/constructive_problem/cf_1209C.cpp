#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
void solve()
{
  int n;cin>>n;
  string s,t;
  cin>>s>>t;
  vector<pii>ops;
  vector<int>pos;
  vector<vector<int>>pat(2);
  for(int i=0;i<n;++i)
  {
    if(s[i]!=t[i])
    {
        pos.push_back(i);
        if(s[i]=='a')
        {
            pat[0].push_back(i);
        }
        else
        {
            pat[1].push_back(i);
        }
    }
  }
  if(pos.size()%2)
  {
    cout<<-1<<'\n';
    return;
  }
  int p0=0,p1=0;
  auto siz=pat[0].size()-1;
  while(p0<((int)pat[0].size()-1))
  {
    ops.push_back({pat[0][p0+1],pat[0][p0]});
    p0+=2;
  }
  while(p1<((int)pat[1].size()-1))
  {
    ops.push_back({pat[1][p1+1],pat[1][p1]});
    p1+=2;
  }
  while(p0<pat[0].size()&&p1<pat[1].size())
  {
    ops.push_back({pat[0][p0],pat[0][p0]});
    ops.push_back({pat[0][p0++],pat[1][p1++]});
  }
  cout<<ops.size()<<'\n';
  for(auto& k:ops)
  {
    cout<<k.second+1<<' '<<k.first+1<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}