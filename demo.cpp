#include <bits/stdc++.h>
using namespace std;
    bool possibleToStamp(vector<vector<int>>& g, int sh, int sw) {
        int n=g.size(),m=g[0].size();
        vector sum(n+1,vector<int>(m+1));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+g[i-1][j-1];
            }
        }
        vector dif(n+2,vector<int>(m+2));
        for(int i=1;i+sh-1<=n;++i)
        {
            for(int j=1;j+sw-1<=m;++j)
            {
                int p=i+sh-1,q=j+sw-1;
                int s=sum[p][q]-sum[i-1][q]-sum[p][j-1]+sum[i-1][j-1];
                if(s==0)
                {
                    ++dif[i][j];
                    --dif[p+1][j];
                    --dif[i][q+1];
                    ++dif[p+1][q+1];
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                dif[i][j]=dif[i][j]+dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(dif[i][j]==0&&g[i-1][j-1]==0)return false;
            }
        }
        return true;
    }
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>>mp={{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
  possibleToStamp(mp,4,3);
  return 0;
}