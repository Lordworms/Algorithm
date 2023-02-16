#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<vector<int>>num(2);
  for(int i=0;i<n;++i)
  {
    int x;
    cin>>x;
    if(x%2)
    {
        num[1].push_back(i);
    }
    else
    {
        num[0].push_back(i);
    }
  }
  if(num[1].size()>=3)
  {
    cout<<"YES"<<'\n';
    cout<<num[1][0]+1<<' '<<num[1][1]+1<<' '<<num[1][2]+1<<'\n';
  }
  else if(num[0].size()>=2&&num[1].size()>=1)
  {
    cout<<"YES\n";
    cout<<num[0][0]+1<<' '<<num[0][1]+1<<' '<<num[1][0]+1<<'\n';
  }
  else 
  {
    cout<<"NO\n";
  }
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