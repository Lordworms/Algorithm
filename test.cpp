#include <bits/stdc++.h>
using namespace std;
const int yzh = 1000000007, N = 1000+5;

int f[N][N], sz[N], t, n, u, v, g[N], fac[N], ifac[N];
struct tt {
    int to, nxt, c;//0->
} edge[N<<1];
int path[N], top;
char sign;

int C(int n, int m) {return 1ll*fac[n]*ifac[m]%yzh*ifac[n-m]%yzh; }
void dfs(int u, int fa) {
    f[u][1] = sz[u] = 1;
    for (int v, i = path[u]; i; i = edge[i].nxt)
        if ((v = edge[i].to) != fa) {
            dfs(v, u);
            memcpy(g, f[u], sizeof(g));
            memset(f[u], 0, sizeof(g));
            if (edge[i].c == 0) {
                for (int i = 1; i <= sz[u]; i++)
                    for (int k = i; k <= i+sz[v]-1; k++)
                        (f[u][k] += 1ll*C(k-1, i-1)*C(sz[u]+sz[v]-k, sz[u]-i)%yzh*g[i]%yzh*(f[v][sz[v]]-f[v][k-i])%yzh) %= yzh;
            } else {
                for (int i = 1; i <= sz[u]; i++)
                    for (int k = i+1; k <= i+sz[v]; k++)
                        (f[u][k] += 1ll*C(k-1, i-1)*C(sz[u]+sz[v]-k, sz[u]-i)%yzh*g[i]%yzh*f[v][k-i]%yzh) %= yzh;               
            }
            sz[u] += sz[v];
        }
    for (int i = 1; i <= n; i++) (f[u][i] += f[u][i-1]) %= yzh;
}
void add(int u, int v, int c) {
    edge[++top] = (tt){v, path[u], c};
    path[u] = top;  
}
int main() {
    n = 1000;
    ifac[0] = ifac[1] = fac[0] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = -1ll*yzh/i*ifac[yzh%i]%yzh;
    for (int i = 1; i <= n; i++)
        ifac[i] = 1ll*ifac[i]*ifac[i-1]%yzh,
        fac[i] = 1ll*i*fac[i-1]%yzh;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); top = 0;
        for (int i = 1; i <= n; i++) {
            path[i] = sz[i] = 0;
            for (int j = 1; j <= n; j++) f[i][j] = 0;
        }
        for (int i = 1; i < n; i++) {
            scanf("%d %c %d", &u, &sign, &v); ++u, ++v;
            if (sign == '<') add(u, v, 0), add(v, u, 1);
            else add(u, v, 1), add(v, u, 0);
        }
        dfs(1, 0);
        printf("%d\n", (f[1][n]+yzh)%yzh);
    }
    return 0;
}