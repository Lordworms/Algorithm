/*
题意：你还记得那条风靡全球的贪吃蛇吗？
我们在一个 n*n 的网格上构建了新的迷宫地图，蛇的长度为 2，也就是说它会占去两个单元格。蛇会从左上角（(0, 0) 和 (0, 1)）开始移动。我们用 0 表示空单元格，用 1 表示障碍物。蛇需要移动到迷宫的右下角（(n-1, n-2) 和 (n-1, n-1)）。

每次移动，蛇可以这样走：
如果没有障碍，则向右移动一个单元格。并仍然保持身体的水平／竖直状态。
如果没有障碍，则向下移动一个单元格。并仍然保持身体的水平／竖直状态。
如果它处于水平状态并且其下面的两个单元都是空的，就顺时针旋转 90 度。蛇从（(r, c)、(r, c+1)）移动到 （(r, c)、(r+1, c)）。
如果它处于竖直状态并且其右面的两个单元都是空的，就逆时针旋转 90 度。蛇从（(r, c)、(r+1, c)）移动到（(r, c)、(r, c+1)）。
返回蛇抵达目的地所需的最少移动次数。
题解：三维dp，dp[i][j][0]表示到达(i,j)且当前为水平方向的最少移动次数  当前蛇尾处于(i,j)位置
            dp[i][j][1]表示到达(i,j)且当前为竖直方向的最少移动次数  当前蛇尾处于(i,j)位置
     我们一共有6个状态转移方程，按照当前是水平或者竖直状态分类，分别为
     dp[i][j][0]=dp[i-1][j][0]+1 || dp[i+1][j-1][1]+1||dp[i+1][j-1][1]+1
     dp[i][j][1]=dp[i][j-1][1]+1||dp[i-1][j][1]+1||dp[i-1][j+1][0]+1

*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minimumMoves(vector<vector<int>>& grid) {
      int m=grid.size(),n=grid[0].size();
      const int maxn=1e9+7;
      vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,maxn)));
      dp[0][0][0]=0;
      for(int i=0;i<m;++i)
      {
        for(int j=0;j<n;++j)
        {
            if(grid[i][j]==1)continue;//此路不通
            //开始更新水平的部分
            if(j+1<n&&grid[i][j+1]==0)
            {
                if(i-1>=0)//从上方转移
                {
                  dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+1);
                }
                if(j-1>=0)//从左边转移
                {
                  dp[i][j][0]=min(dp[i][j][0],dp[i][j-1][0]+1);
                }
                if(i+1<m&&grid[i+1][j]==0&&grid[i+1][j+1]==0)//由于需要计算出之前的dp[i][j][0]才能算出dp[i][j][1]这里更新第二种情况的第三个方程
                {
                  dp[i][j][1]=min(dp[i][j][1],dp[i][j][0]+1);
                }
            }
            if(i+1<m&&grid[i+1][j]==0)
            {
                if(i-1>=0)
                {
                  dp[i][j][1]=min(dp[i][j][1],dp[i-1][j][1]+1);
                }
                if(j-1>=0)
                {
                  dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+1);
                }
                if(j+1<n&&grid[i][j+1]==0&&grid[i+1][j+1]==0)
                {
                  dp[i][j][0]=min(dp[i][j][0],dp[i][j][1]+1);
                }
            }
        }
      }
      return dp[m-1][n-2][0]==maxn?-1:dp[m-1][n-2][0];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  return 0;
}