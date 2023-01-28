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
  int n,m,q;
  cin>>n>>m>>q;
  DSU dsu(n+2);
  vector st(1<<(int)(log2(n)+1),vector<int>(30));
  vector<vector<int>>E(n+1);
  vector<int>cnt(n+1);
  for(int i=1;i<=n;++i)E[i].push_back(i);
  for(int i=1;i<=m;++i)
  {
    int x,y;
    cin>>x>>y;
    int fax=dsu.f[x],fay=dsu.f[y];
    if(fax==fay)continue;
    if(E[fax].size()<E[fay].size())
    {
        swap(fax,fay);
    }
    for(int now:E[fay])
    {
        if(now!=1&&dsu.f[now-1]==fax)
        {
            cnt[now-1]=i;
        }
        if(now!=n&&dsu.f[now+1]==fax)
        {
            cnt[now]=i;
        }
    }
    for(int now:E[fay])//should do after it 
    {
        dsu.f[now]=fax;
        E[fax].push_back(now);
    }
  }
  for(int i=1;i<=n;++i)st[i][0]=cnt[i];
  for(int j=1;j<=20;++j)
  {
    for(int i=1;i<=n&&i+(1<<(j))-1<=n;++i)
    {
        st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
  }
  auto query=[&](int l,int r)
  {
    int k=log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
  };
  for(int i=0;i<q;++i)
  {
    int l,r;
    cin>>l>>r;
    if(l==r)cout<<'0'<<" \n"[i==q-1];
    else cout<<query(l,r-1)<<" \n"[i==q-1];
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