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
struct node
{
    int a,b,w;
};
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<node>a(m);
  for(int i=0;i<m;++i)
  {
    cin>>a[i].a>>a[i].b>>a[i].w;
  }
  sort(a.begin(),a.end(),[&](node a,node b)
  {
    return a.w>b.w;
  });  
  DSU dsu(2*(n+1));
  for(int i=0;i<m;++i)
  {
    if(dsu.same(a[i].a,a[i].b))
    {
        cout<<a[i].w;
        return;
    }
    dsu.merge(a[i].a+n,a[i].b);
    dsu.merge(a[i].b+n,a[i].a);
  }
  cout<<0<<'\n';
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