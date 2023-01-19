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
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[fa(x)]; }
};
void solve()
{
  int n;
  cin>>n;
  vector a(n,vector<ll>(n,0));
  DSU dsu(2*n+2);
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<n;++j)
    {
        cin>>a[i][j];
    }
  }
  for(int i=0;i<n;++i)
  {
    for(int j=i+1;j<n;++j)
    {
        if(a[i][j]==a[j][i]||dsu.same(i+1,j+1)||dsu.same(i+1,j+n+1))continue;
        if(a[i][j]>a[j][i])//need to swap, make them different
        {
            dsu.merge(i+1,j+n+1);
            dsu.merge(i+n+1,j+1);
        }
        else//do not need to swap, make them the same
        {
            dsu.merge(i+1,j+1);
            dsu.merge(i+n+1,j+n+1);
        }
    }
  }
  for(int i=0;i<n;++i)
  {
    if(dsu.fa(i+1)<=n)
    {
        for(int j=0;j<n;++j)
        {
            swap(a[i][j],a[j][i]);
        }
    }
  }
  for(int i=0;i<n;++i)
  {
    for(int j=0;j<n;++j)
    {
        cout<<a[i][j]<<" \n"[j==n-1];
    }
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