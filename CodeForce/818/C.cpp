/*
    just need to think about the impossible situation!!!!
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n),b(a);
  for(int i=0;i<n;++i)
  {
    cin>>a[i];
  }
  bool valid=true;
  for(int i=0;i<n;++i)
  {
    cin>>b[i];
    if(b[i]<a[i])
    {
        valid=false;
    }
  }
  if(!valid)
  {
    cout<<"NO"<<'\n';
    return;
  }
  b.push_back(b[0]);
  for(int i=0;i<n;++i)
  {
    if(a[i]==b[i])continue;
    if(b[i]>b[i+1]+1)
    {
        valid=false;
        break;
    }
  }
  cout<<(valid?"YES":"NO")<<'\n';
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