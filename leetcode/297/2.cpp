/*
    题面：给出大小为mxn的矩阵，只能够由上一层移动到下一层，并且移动的代价为边+点的值，求从第一层移动到最后一层的最小代价
    题解：初始化dis[0][i]=grid[0][i];
        dis[i][j]=min(dis[i][j],dis[i-1][k]+grid[i][j]+cost[grid[i-1][k]][j]);
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MAXN=1e9+7;
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
       int m=grid.size(),n=grid[0].size();
       vector<vector<int>>dis(m+1,vector<int>(n+1,MAXN));
       for(int i=0;i<n;++i)dis[0][i]=grid[0][i];
       for(int i=1;i<m;++i)
       {
           for(int k=0;k<n;++k)
           {
               for(int j=0;j<n;++j)
               {
                   dis[i][k]=min(dis[i][k],dis[i-1][j]+moveCost[grid[i-1][j]][k]+grid[i][k]);
               }
           }
       }
       int ans=MAXN;
       for(int i=0;i<n;++i)ans=min(ans,dis[m-1][i]);
       return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}