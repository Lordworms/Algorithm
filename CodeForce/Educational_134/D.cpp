/*
    let's finish the problem with the highest bit
    if ans[i] could be 1, then the number of 1 in a and number of 0 equals
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n),b(a);
  for(int i=0;i<n;++i)cin>>a[i];
  for(int i=0;i<n;++i)cin>>b[i];
  int ans=0,bit;
  for(int i=29;i>=0;--i)
  {
    ans|=(1<<i);
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        mp[ans&a[i]]++;
        mp[ans&(~b[i])]--;
    }
    bool flag=true;
    for(auto& k:mp)
    {
        if(k.second!=0)
        {
            flag=false;
            break;
        }
    }
    if(!flag)
    {
       ans^=(1<<i);
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