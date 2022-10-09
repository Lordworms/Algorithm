/*
    别给老子多想，就直接全量的数组，别整什么cur，pre

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
    int n, m;
    const int MOD = 1000000007;

public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        n = grid.size(); m = grid[0].size();

        long long f[n][m][K];
        memset(f, 0, sizeof(f));
        // 初值
        f[0][0][grid[0][0] % K] = 1;

        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < K; k++) {
            // 从上方走过来
            if (i > 0) f[i][j][(k+grid[i][j])%K] = (f[i][j][(k+grid[i][j])%K] + f[i - 1][j][k]) % MOD;
            // 从左方走过来
            if (j > 0) f[i][j][(k+grid[i][j])%K] = (f[i][j][(k+grid[i][j])%K] + f[i][j  - 1][k]) % MOD;
        }
        return f[n - 1][m - 1][0];
    }
};
int main()
{
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<vector<int>>arr={{5,2,4},{3,0,5},{0,7,2}};
  sol.numberOfPaths(arr,3);
  return 0;
}