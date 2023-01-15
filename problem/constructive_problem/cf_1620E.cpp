#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=5e5+10;
void solve()
{
  int q;
  cin>>q;
  int x,y;
  vector<vector<int>>S(MAXN);
  vector<int>ans;
  for(int i=0;i<q;++i)
  {
    int k;
    cin>>k;
    switch(k)
    {
        case 1:
        {
            cin>>x;
            S[x].push_back(ans.size());
            ans.push_back(x);
            break;
        }
        case 2:
        {
            cin>>x>>y;
            if(x!=y)
            {
                if(S[x].size()>S[y].size())S[x].swap(S[y]);
                for(auto& k:S[x])
                {
                    S[y].push_back(k);
                }
                S[x].clear();
            }
            break;
        }
    }
  }
  for(int i=0;i<MAXN;++i)
  {
    for(auto& k:S[i])
    {
        ans[k]=i;
    }
  }
  for(int i=0;i<ans.size();++i)
  {
    cout<<ans[i]<<" \n"[i==ans.size()-1];
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}