#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  string s;
  cin>>n>>s;
  int cnt=0;
  int last=-1;
  int ans=0;
  for(int i=0;i<n;++i)
  {
    int c=s[i]-'0';
    if(last==-1&&c)
    {
        last=c;
    }
    if(c==0&&last==1)
    {
        ++ans;
        last=c;
    }
    else if(c==1&&last==0)
    {
        ++ans;
        last=c;
    }
  
  }
  cout<<ans<<'\n';
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