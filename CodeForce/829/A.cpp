#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  string s; 
  cin>>n>>s;
  int q=0;
  for(int i=0;i<n;++i)
  {
    if(s[i]=='Q')++q;
    if(s[i]=='A')
    {
        if(i==0)
        {
            cout<<"NO"<<'\n';
            return;
        }
        if(q>=1)--q;
    }
  }
  if(q)
  {
    cout<<"NO"<<'\n';
    return;
  }
  cout<<"YES"<<'\n';
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