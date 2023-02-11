/*
    if each number has a bit which occurs once in all bits, then no
    else YES

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  map<int,vector<int>>num;
  map<int,int>mp;
  bool flag=false;
  int n;
  cin>>n;
  for(int i=0;i<n;++i)
  {
    int k;cin>>k;
    for(int j=0;j<k;++j)
    {
        int x;cin>>x;
        num[i].push_back(x);
        mp[x]++;
    }
  } 
  for(auto & k:num)
  {
    flag=false;
    for(int v:k.second)
    {
        if(mp[v]==1)
        {
            flag=true;
            break;
        }
    }
    if(!flag)
    {
        break;
    }
  }
  cout<<(!flag?"YES\n":"NO\n");
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