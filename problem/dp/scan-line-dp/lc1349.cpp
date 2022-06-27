/*
题意：
    给你一个 m * n 的矩阵 seats 表示教室中的座位分布。如果座位是坏的（不可用），就用 '#' 表示；否则，用 '.' 表示。
    学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。请你计算并返回该考场可以容纳的一起参加考试且无法作弊的最大学生人数。
    学生必须坐在状况良好的座位上。
题解：轮廓线dp，简单题
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
     vector<vector<bool>>isvalid;
     bool check(int i,int j,int mask){
          if(j>0&&isvalid[i][j-1]&&(mask&1)==1)return true;//左边
          if(j>0&&i>0&&isvalid[i-1][j-1]&&(((mask>>n)&1)==1))return true;//左上
          if(j<n-1&&i>0&&isvalid[i-1][j+1]&&((mask>>(n-2))&1)==1)return true;//右上
          return false;
        }
    int maxStudents(vector<vector<char>>& seats) {
        m=seats.size(),n=seats[0].size();
        isvalid.resize(m*n+1,vector<bool>(n,true));
        for(int i=0;i<m;++i)for(int j=0;j<n;++j)if(seats[i][j]=='#')isvalid[i][j]=false;
        int maxMask=1<<(n+1);
        vector<vector<int>>dp(m*n+1,vector<int>(maxMask,0));
        int i,j;
       
        for(int id=m*n-1;id>=0;--id)
        {
            i=id/n,j=id%n;
            for(int mask=0;mask<maxMask;++mask)
            {
              int now=(mask<<1)%maxMask;//去掉第一位
              dp[id][mask]=max(dp[id][mask],dp[id+1][now]);
              if(!isvalid[i][j]||check(i,j,mask))continue;
              dp[id][mask]=max(dp[id][mask],dp[id+1][now+1]+1);
            }
        }
        return dp[0][0];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<vector<char>>seats={{'#','.','#'},{'#','#','.'},{'.','#','.'}};
  cout<<sol.maxStudents(seats);
  return 0;
}