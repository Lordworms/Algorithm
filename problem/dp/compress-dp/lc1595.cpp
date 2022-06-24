/*
   题面：给你两组点，其中第一组中有 size1 个点，第二组中有 size2 个点，且 size1 >= size2 。
       任意两点间的连接成本 cost 由大小为 size1 x size2 矩阵给出，其中 cost[i][j] 是第一组中的点 i 和第二组中的点 j 的连接成本。如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。
       返回连通两组点所需的最小成本。
   题解：状态压缩dp，我们用dp[i][mask]表示左侧0-i个节点和右侧mask连接的最小代价，则最终答案为dp[m-1][1<<n-1]状态转移方程为
        dp[i][j|k]=min(dp[i][j|k],min(dp[i-1][j],dp[i][j])+cost[i-1][k])
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m=cost.size(),n=cost[0].size();
        vector<vector<int>>dp(m+1,vector<int>(1<<n,INT_MAX));
        dp[0][0]=0;
        for(int i=1;i<=m;++i)
        {
            for(int j=0;j<((1<<n));++j)
            {
                for(int k=0;k<n;++k)
                {
                    
                        dp[i][j|k]=min(dp[i][j|k],min(dp[i-1][j],dp[i][j])+cost[i-1][k]);
                }
            }
        }
        return dp[m-1][(1<<n)-1];
    }    
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<vector<int>>mp={{1,3,5},{4,1,1},{1,5,3}};
  sol.connectTwoGroups(mp);
  return 0;
}