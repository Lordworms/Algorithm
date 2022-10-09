#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const static int MAXN=5e4+10;
    const int MOD=1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int cur,pre;
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n,vector<int>(k,0)));
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<m;++i)
        {
          cur=i&1,pre=cur^1;
          for(int j=0;j<n;++j)
          {
            int now=grid[i][j];
            for(int x=0;x<k;++x)
            {
              if(i>0)
              {
                 dp[cur][j][(now+x)%k]+=dp[pre][j][x];
                 dp[cur][j][(now+x)%k]%=MOD;
              }
              if(j>0)
              {
                 dp[cur][j][(now+x)%k]+=dp[cur][j-1][x];
                 dp[cur][j][(now+x)%k]%=MOD;
              }
            }
          }
        }
        return dp[cur][n-1][0];     
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<vector<int>>path={{1},{5},{3},{7},{3},{2},{3},{5}};
  sol.numberOfPaths(path,29);
  return 0;
}