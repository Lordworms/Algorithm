#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int fa(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return fa(x) == fa(y); }
    bool merge(int x, int y) {
        x = fa(x);
        y = fa(y);
        int minxy=min(x,y);
        int maxxy=max(x,y);
        if (x == y) return false;
        siz[maxxy] += siz[minxy];
        f[minxy] = maxxy;
        return true;
    }
    int size(int x) { return siz[fa(x)]; }
};
void solve()
{
  int n,m;
  cin>>n>>m;
  DSU dsu(n);
  for(int i=0;i<m;++i)
  {
    int u,v;
    cin>>u>>v;
    u--,v--;
    dsu.merge(u,v);
  }
  int j=0,ans=0;
  for(int i=0;i<n;++i)
  {
    int f=dsu.fa(i);
    for(;j<f;++j)
    {
        if(dsu.fa(j)!=dsu.fa(i))
        {
            dsu.merge(j,f);
            ++ans;
        }
    }
    j=f+1;
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}