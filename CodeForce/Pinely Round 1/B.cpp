#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    map<int,int>mp;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        mp[x]++;
    }
    if(n==1)
    {
        cout<<1<<"\n";
        return;
    }
    if(mp.size()==2)
    {
        cout<<n-(*(mp.begin())).second+1<<"\n";
        return;
    }
    cout<<n<<"\n";
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