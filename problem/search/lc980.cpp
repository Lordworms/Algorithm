/*
    题面:在二维网格 grid 上，有 4 种类型的方格：
        1 表示起始方格。且只有一个起始方格。
        2 表示结束方格，且只有一个结束方格。
        0 表示我们可以走过的空方格。
        -1 表示我们无法跨越的障碍。
        返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。

        每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<bool>>vis;
    int ans=0,m,n,able=0,si,sj,ei,ej;
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>>mp;
public:
    void dfs(int ni,int nj,int access,int road)
    {
        if(road>=able+1)return;//重点：增加剪枝
        if(ni==ei&&nj==ej)
        {
            if(access==able)ans++;
            return;
        }
        for(int i=0;i<4;++i)
        {
            int ii=ni+dir[i][0],ij=nj+dir[i][1];
            if(ii>=m||ii<0||ij<0||ij>=n||mp[ii][ij]==-1||vis[ii][ij])continue;
            vis[ii][ij]=true;
            if(mp[ii][ij]==0)dfs(ii,ij,access+1,road+1);
            else dfs(ii,ij,access,road);
            vis[ii][ij]=false;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vis.resize(m,vector<bool>(n,false));
        mp=grid;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1)
                {
                    si=i,sj=j;
                }
                else if(grid[i][j]==2)
                {
                    ei=i,ej=j;
                }
                else if(grid[i][j]==0)
                {
                    able++;
                }
            }
        }
        vis[si][sj]=true;
        dfs(si,sj,0,0);
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<vector<int>>mp={{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
  cout<<sol.uniquePathsIII(mp)<<endl;
  return 0;

}