#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int MOD = 998244353;

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int binpow(int a, int b){
	int res = 1;
	while (b){
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	--n;
	vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
	vector<vector<int>> C(n + 1);
	forn(i, n + 1){
		C[i].resize(i + 1);
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	}
	dp[0][0] = 1;
	forn(i, k) forn(t, n + 1) {
		int pw = binpow(k - i, t * (t - 1) / 2);
		int step = binpow(k - i, t);
		forn(j, n - t + 1){
			dp[i + 1][j + t] = add(dp[i + 1][j + t], mul(dp[i][j], mul(C[n - j][t], pw)));
			pw = mul(pw, step);
		}
	}
	printf("%d\n", dp[k][n]);
}