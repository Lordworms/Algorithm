#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  string a,b;
  cin>>a>>b;
  if(a.size()!=b.size())
  {
    cout<<"NO"<<'\n';
    return;
  }
  bool aa=false,bb=false;
  for(int i=0;i<a.size();++i)if(a[i]=='1')
  {
    aa=true;
    break;
  }
  for(int i=0;i<b.size();++i)if(b[i]=='1')
  {
    bb=true;
    break;
  }
  if(aa&&bb||!(aa||bb))
  {
    cout<<"YES\n";
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}