#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  multiset<int>a,b;
  int n;cin>>n;
  for(int i=0;i<n;++i)
  {
    int x;cin>>x;
    while(x%2==0)x/=2;
    a.insert(x);
  }
  for(int i=0;i<n;++i)
  {
    int x;
    cin>>x;
    b.insert(x);
  }
  while(!b.empty())
  {
    int x=*b.rbegin();
    if(!a.count(x))
    {
        if(x==1)
        {
            break;
        }
        b.erase(b.find(x));
        b.insert(x/2);
    }
    else
    {
        b.erase(b.find(x));
        a.erase(a.find(x));
    }
  }
  cout<<(b.empty()?"YES":"NO")<<'\n';
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