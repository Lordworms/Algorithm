#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<int>a(n);
  string s(m,'B');
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
    --a[i];
    int minx=min(a[i],m-a[i]-1),maxx=max(a[i],m-a[i]-1);
    if(s[minx]=='B')
    {
        s[minx]='A';
    }
    else
    {
        s[maxx]='A';
    }
  }
  cout<<s<<'\n';
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