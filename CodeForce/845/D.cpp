/*
    https://zhuanlan.zhihu.com/p/600473200
    没全懂
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}
template<class T>
T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct BZ {
    int x;
    BZ(int x = 0) : x(norm(x)) {}
    BZ(ll x) : x(norm(x % MOD)) {}
    int val() const {
        return x;
    }
    BZ operator-() const {
        return BZ(norm(MOD - x));
    }
    BZ inv() const {
        return power(*this, MOD - 2);
    }
    BZ &operator*=(const BZ &rhs) {
        x = ll(x) * rhs.x % MOD;
        return *this;
    }
    BZ &operator+=(const BZ &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    BZ &operator-=(const BZ &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    BZ &operator/=(const BZ &rhs) {
        return *this *= rhs.inv();
    }
    friend BZ operator*(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res *= rhs;
        return res;
    }
    friend BZ operator+(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res += rhs;
        return res;
    }
    friend BZ operator-(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res -= rhs;
        return res;
    }
    friend BZ operator/(const BZ &lhs, const BZ &rhs) {
        BZ res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, BZ &a) {
        ll v;
        is >> v;
        a = BZ(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const BZ &a) {
        return os << a.val();
    }
};
void solve()
{
  int n;
  cin>>n;
  vector<vector<int>>edges(n+1);
  vector<int>height(n+1);
  for(int i=0;i<n-1;++i)
  {
    int x,y;
    cin>>x>>y;
    edges[x].push_back(y);
    edges[y].push_back(x);
  }
  function<void(int,int)>dfs=[&](int x,int fa)
  {
    height[x]=1;
    for(int v:edges[x])
    {
        if(v==fa)continue;
        dfs(v,x);
        height[x]=max(height[v]+1,height[x]);
    }
  };
  dfs(1,-1);
  BZ ans=0;
  for(int i=1;i<height.size();++i)ans+=height[i];
  cout<<ans*power(BZ(2),n-1)<<'\n';
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