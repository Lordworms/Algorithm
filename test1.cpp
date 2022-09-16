#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 105, C = 1e8;

struct piii {
    int d, l, f;
    piii (int _d = 0, int _l = 0, int _f = 0) {
        d = _d, l = _l, f = _f; 
    }
    bool operator < (const piii &b) const {
        if (d == b.d && f == b.f) return l < b.l;
        if (f == b.f) return d > b.d;
        return f < b.f;
    }
    bool operator == (const piii &b) const {
        return d == b.d && l == b.l && f == b.f;
    }
};
int n, m, mc, a[N], w[N], f[N][N], c;
int maxd, head, tail;
map<pii, bool> mp;
piii q[N<<3], t;
pii v;

void bfs() {
    t = piii(1, 0, 1);
    q[head = tail = 1] = t;
    mp[pii(0, 1)] = 1;
    while (head <= tail) {
        t = q[head++];
        if (t.d >= maxd) continue;
        if (mp[v = pii(t.l+1, t.f)] == 0) {
            mp[v] = 1;
            q[++tail] = piii(t.d+1, t.l+1, t.f);
        }
        if (t.l > 1 && 1ll*t.f*t.l <= C && mp[v = pii(t.l, t.f*t.l)] == 0) {
            mp[v] = 1;
            q[++tail] = piii(t.d+1, t.l, t.f*t.l);
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &mc);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    memset(f, -1, sizeof(f));
    f[0][0] = mc;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            if (f[i-1][j]-a[i] >= 0)
                f[i][j] = max(min(f[i-1][j]-a[i]+w[i], mc), f[i][j]);
            if (j && f[i-1][j-1]-a[i] >= 0)
                f[i][j] = max(f[i-1][j-1]-a[i], f[i][j]);
            if(f[i][j]>=0)maxd=max(maxd,j);
        }
    /*
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++)
            if (f[i][j] >= 0) maxd = max(maxd, j);
    */
    bfs();
    sort(q+1, q+tail+1);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c); int r;
        if (c <= maxd) {
            puts("1"); continue;    
        }
        for (int i = 1; i <= tail; i++)
            if (q[i].f <= c && q[i].f+maxd-q[i].d >= c) {
                puts("1"); goto qwq;
            }
        r = tail;
        for (int l = 1; l <= r; l++) {
            while (l <= r && q[l].f+q[r].f > c) --r;
            if (l <= r && q[l].f+q[r].f+maxd-q[l].d-q[r].d >= c) {
                puts("1"); goto qwq;
            }
        }
        puts("0");
        qwq: 1;
    }
    return 0;
}