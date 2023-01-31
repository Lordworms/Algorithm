/*
    brute force works!
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  map<int,int>cnt;
  for(int i=0;i<n;++i)
  {
    int x;
    cin>>x;
    cnt[x]++;
  }
  while(cnt.size()>1)
  {
    map<int,int>tmp;
    for(auto it=cnt.begin();it!=cnt.end();++it)
    {
        int d=it->second-1;
        if(d)
        {
            tmp[0]+=d;
        }
        auto iit=next(it);
        if(iit!=cnt.end())
        {
            tmp[iit->first-it->first]++;
        }
    }
    cnt=tmp;
  }
  if(cnt.begin()->second>1)
  {
    cout<<0<<'\n';
  }
  else
  {
    cout<<cnt.begin()->first<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}