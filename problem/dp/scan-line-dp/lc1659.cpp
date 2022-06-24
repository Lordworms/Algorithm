/*
题意：
    给你四个整数 m、n、introvertsCount 和 extrovertsCount 。有一个 m x n 网格，和两种类型的人：内向的人和外向的人。总共有 introvertsCount 个内向的人和 extrovertsCount 个外向的人。

    请你决定网格中应当居住多少人，并为每个人分配一个网格单元。 注意，不必 让所有人都生活在网格中。

    每个人的 幸福感 计算如下：

    内向的人 开始 时有 120 个幸福感，但每存在一个邻居（内向的或外向的）他都会 失去  30 个幸福感。
    外向的人 开始 时有 40 个幸福感，每存在一个邻居（内向的或外向的）他都会 得到  20 个幸福感。
    邻居是指居住在一个人所在单元的上、下、左、右四个直接相邻的单元中的其他人。

    网格幸福感 是每个人幸福感的 总和 。 返回 最大可能的网格幸福感 。
题解：滑动窗口状压：
    用dp[i][j][x][y][status]表示前n个格子的状态为status，且当前的横坐标为i，纵坐标为j，x为剩余的A类人，y为剩余的B类人
    i = coor/n, j = coor%n
    first = status/pow(3, n-1)
    last = status%3
    status = (status*3)%pow(3,n)
    我们可以发现，最多只有可能有之前的n个方格和当前的格子产生关系，所以我们得存储前n个方格的状态
    然后状态转移也很好做
    我们用一个统一的量来表示其序号
    dp[i][x][y][status_now]=max(dp[i][x][y][status_now],income[before][1]+dp[i][x-1][y][status+1])//添加内向
    同理可得添加外向的人的转移方程
    需要注意的是
    income[3][3]={0,0,0,0,-60,}

    
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
      int all=pow(3,n);
      int mod=pow(3,n-1);
      int dp[m*n+1][introvertsCount+1][extrovertsCount+1][all];
      memset(dp,0,sizeof(dp));
      int income[3][3]={0,0,0,0,-60,-10,0,-10,40};
      for(int id=m*n-1;id>=0;--id)
      {
        int i=id/n,j=id%n;
        for(int x=0;x<=introvertsCount;++x)
        {
          for(int y=0;y<=extrovertsCount;++y)
          {
              for(int pre=0;pre<all;++pre)
              {
                  int now=(pre*3)%all;
                  int come;
                  if(x>0)
                  {
                    come=120+(j!=0)*income[1][pre%3]+income[1][pre/mod];//左边和上面的贡献值
                    dp[id][x][y][pre]=max(dp[id][x][y][pre],come+dp[id+1][x-1][y][now+1]);
                  }
                  if(y>0)
                  {
                    come=40+(j!=0)*income[2][pre%3]+income[2][pre/mod];
                    dp[id][x][y][pre]=max(dp[id][x][y][pre],come+dp[id+1][x][y-1][now+2]);
                  }
                dp[id][x][y][pre]=max(dp[id][x][y][pre],dp[id+1][x][y][now]);
              }
          }
        }
      }
      int ans= dp[0][introvertsCount][extrovertsCount][0];
      return ans;//到了起始位置，所以前面n个为0
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.getMaxGridHappiness(2,3,1,2);
  return 0;
}