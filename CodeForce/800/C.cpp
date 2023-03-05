/*
    *ptr+1 ptr+1
    *ptr-1 ptr-1
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<ll>pre(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>pre[i];
    pre[i]+=pre[i-1];
  }
  if(pre[n]!=0)
  {
    cout<<"NO\n";
    return;
  }
  bool ispre_zero=false;
  for(int i=1;i<=n;++i)
  {
    if(pre[i]==0)
    {
        ispre_zero=true;
        continue;
    }
    if(ispre_zero)
    {
        if(pre[i]!=0)
        {
            cout<<"NO\n";
            return;
        }
    }
    if(pre[i]<0)
    {
        cout<<"NO\n";
        return;
    }
  }
  cout<<"YES\n";
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