/*
the w between i and j is f(i,i)+f(j,j)-2*f(i,j)
(think about why!)
why should we sort
*/
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
    cin>>n;
    vector<tuple<ll,int,int>>E;
    vector<ll>F(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(i==j)
            {
                cin>>F[i];
            }
            else 
            {
                ll w;
                cin>>w;
                E.push_back({w,j,i});
            }
        }
    }
    sort(E.begin(),E.end(),std::greater());
    DSU arr(n);
    for(auto [w,a,b]:E)
    {
        if(arr.same(a,b))
        {
            continue;
        }
        arr.merge(a,b);
        cout<<a+1<<' '<<b+1<<' '<<(F[a]+F[b]-2*w)/n<<'\n';
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
  solve();
  return 0;
}