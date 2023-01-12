#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5+5;
 
ll sum[N]{0}, a[N], dp[N], f[N];
int Q[N];
 
int main() {
    int n, m, p, h;
    cin >> n >> m >> p;
    for(int i = 1; i < n; i++) { scanf("%lld", &f[i]); sum[i+1] = sum[i]+f[i];}
    for(int i = 1; i <= m; i++) { scanf("%d%lld", &h, &a[i]); a[i] -= sum[h]; }
    sort(a+1, a+m+1);
    for(int i = m; i >= 1; i--) a[i] -= a[1];
    for(int i = 1; i <= m; i++) {
        sum[i] = sum[i-1]+a[i];
        dp[i] = a[i]*i-sum[i];
    }
 
    for(int j = 1; j < p; j++) {
        for(int i = 1; i <= m; i++) f[i] = dp[i]+sum[i];
        int h = 0, t = -1;
        for(int i = 1; i <= m; i++) {
            while(h<t && (f[Q[h+1]]-f[Q[h]])<a[i]*(Q[h+1]-Q[h])) ++h;
            while(h<t && (f[Q[t]]-f[Q[t-1]])*(i-Q[t])>(f[i]-f[Q[t]])*(Q[t]-Q[t-1])) --t;
            Q[++t] = i;
            dp[i] = f[Q[h]]+a[i]*(i-Q[h])-sum[i];
        }
    }
    printf("%lld\n", dp[m]);
    return 0;
}