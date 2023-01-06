#include <bits/stdc++.h>
using namespace std;
using ll=long long;
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
  DSU dsu(26);
  string s;
  cin>>n>>s;
  unordered_map<int,int>bef,aft;
  for(int i=0;i<n;++i)
  {
    int p=s[i]-'a';
    if(!bef.count(p))
    {
        for(int q=0;q<26;++q)
        {
            if(!aft.count(q)&&q!=p)
            {
                if(bef.count(q)&&aft.count(p))
                {
                    if(dsu.same(p,q))
                    {
                        if(dsu.size(p)==26)
                        {
                            bef[p]=q;
                            aft[q]=p;
                        }
                    }
                    else
                    {
                        dsu.merge(p,q);
                        bef[p]=q;
                        aft[q]=p;
                    }
                }
                else
                {
                    bef[p]=q;
                    aft[q]=p;
                    dsu.merge(p,q);
                }
                if(bef.count(p))break;
            }
        }
    }
    s[i]=bef[p]+'a';
  }
  cout<<s<<'\n';
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