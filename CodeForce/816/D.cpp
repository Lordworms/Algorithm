/*
    be aware of one thing:
    is that: the minimal value of a such that a|b=x is b^x;
    and the maximum is a&x
    so we can first set every a[i] to (1<<31-1) and then adjust them one by one
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
void solve()
{
  int n,q;
  cin>>n>>q;
  vector<vector<pii>>E(n);
  vector<int>ans(n+1,(1<<31)-1);
  while(q--)
  {
    int i,j,x;
    cin>>i>>j>>x;
    --i,--j;
    if(i>j)
    {
        swap(i,j);
    }
    ans[i]&=x;
    ans[j]&=x;
    E[i].emplace_back(j,x);
    E[j].emplace_back(i,x);
  }
  for(int i=0;i<n;++i)
  {
    int res=0;
    for(auto& [j,x]:E[i])
    {
        if(i==j)
        {
            res=x;
        }
        res|=(ans[j]^x);
    }
    ans[i]=res;
  }
  for(int i=0;i<n;++i)cout<<ans[i]<<" \n"[i==n-1];
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}