/*
    斜率优化DP
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct CHT {
    const ll inf=1e18;
    struct Point {
        int x, y;
        Point() {}
        Point(int _x, int _y): x(_x), y(_y) {}
        double intersect(Point p) {//calculate k, posp>posnow
            double dy = p.y - y;
            double dx = x - p.x;
            return dy / dx;
        }
        // 计算 dis_old[v] + v*v - 2*uv, 
        // 这里k=u x = dis_old[v] + v*v, y = -2*v
        long long operator () (long long k) {
            return k * x + y;
        }
    };

    vector<double> K;
    vector<Point> points;

    void init(Point p) {
        K.push_back(-inf);
        points.push_back(p);
    }

    void addLine(Point p) {
        // 存在 K[yz] <= k[xy]的情况 z = p, y = points[sz-1], x = points[sz-2]
        // 此时丢弃中间节点y 
        while (points.size() >= 2 && p.intersect(points[points.size() - 1]) <= K.back()) {
            K.pop_back();
            points.pop_back();
        }
        if (!points.empty()) {
            K.push_back(p.intersect(points.back()));
        }
        points.push_back(p);
    }

    long long query(long long qk) {
        // 从递增的K序列中，找到最后一个 <= qk 的k[xp]对应的 p节点 
        int id = upper_bound(K.begin(), K.end(), qk) - K.begin();
        --id;
        return points[id](qk);
    }
};
using pii=pair<int,int>;
void solve()
{
  int n,m,k;
  cin>>n>>m>>k;
  vector<vector<pii>>G(n);
    
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