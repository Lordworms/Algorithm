#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>ans(n,0);
  unordered_map<int,vector<int>>pos;
  for(int i=0;i<n;++i)
  {
    int x;
    cin>>x;
    --x;
    pos[x].push_back(i);
  }
  for(auto& k:pos)
  {
    int id=k.first,last=0,end=0;
    for(int i:pos[id])
    {
        if(i-last==1||(i-end+1)%2==0||i==pos[id][0])
        {
            ++ans[id];
            end=i;
        }
        else
        {
            end=last;
        }
        last=i;
    }
  }
  for(int i=0;i<n;++i)
  {
    cout<<ans[i]<<" \n"[i==n-1];
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