/*

    https://zhuanlan.zhihu.com/p/600573819
*/
#include<bits/stdc++.h>
using namespace std;
struct TarjanSCC {
  int n;  // 节点数
  vector<vector<pair<int, int>>> edges;
  vector<int> dfn, low;  // 节点的DFS序、所能追溯到的最小时间戳
  int tim;  // 时间戳
  stack<int> stk;
  vector<bool> state;  // 记录节点是否在栈中
  int sccCnt;  // SCC的个数
  vector<int> id;  // 节点所在的SCC的编号
  vector<int> siz;  // SCC的大小
  vector<int> in, out;  // 缩点后SCC的入度、出度

  TarjanSCC(int _n, const vector<vector<pair<int, int>>>& _edges) :n(_n), edges(_edges) {
    tim = sccCnt = 0;
    dfn.resize(n + 1), low.resize(n + 1), state.resize(n + 1);
    state.resize(n + 1), id.resize(n + 1), siz.resize(n + 1);
    in.resize(n + 1), out.resize(n + 1);

    for (int u = 1; u <= n; u++)
      if (!dfn[u]) tarjan(u);

    for (int u = 1; u <= n; u++) {
      for (auto [v, _] : edges[u]) {
        int a = id[u], b = id[v];
        if (a != b) out[a]++, in[b]++;
      }
    }
  }

  void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    stk.push(u);
    state[u] = true;

    for (auto [v, _] : edges[u]) {
      if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      }
      else if (state[v]) low[u] = min(low[u], dfn[v]);
    }

    if (dfn[u] == low[u]) {  // 该节点是其所在的SCC的顶点
      sccCnt++;
      int cur;
      do {
        cur = stk.top(); stk.pop();
        state[cur] = false;
        id[cur] = sccCnt;
        siz[sccCnt]++;
      } while (cur != u);
    }
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> edges(n + 1);
  int maxw = 0;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    edges[u].push_back({ v,w });
    maxw = max(maxw, w);
  }

  auto check = [&](int mid)->bool {
    auto Edges = edges;
    for (int u = 1; u <= n; u++) {
      for (auto [v, w] : edges[u])
        if (w <= mid) Edges[v].push_back({ u,w });
    }

    TarjanSCC solver(n, Edges);

    int cnt = 0;  // 入度为0的SCC数
    for (int i = 1; i <= solver.sccCnt; i++)
      cnt += !solver.in[i];
    return cnt == 1;
  };

  int l = 0, r = maxw + 1;  // 注意二分的上界+1以判定无解的情况
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  cout << (l == maxw + 1 ? -1 : l) << endl;
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}