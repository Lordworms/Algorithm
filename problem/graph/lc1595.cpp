/*
    题面：给你两组点，其中第一组中有 size1 个点，第二组中有 size2 个点，且 size1 >= size2 。
        任意两点间的连接成本 cost 由大小为 size1 x size2 矩阵给出，其中 cost[i][j] 是第一组中的点 i 和第二组中的点 j 的连接成本。如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。
        返回连通两组点所需的最小成本。
    题解：很明显的km板子题，这里有板子，所以，请
        分别找到左右的最小边，计算最大匹配，然后用对应的最小边和减去最大匹配即为解
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
static const int MAXN=400;
typedef long long ll;
const int INF=0x3f3f3f3f;
int wx[MAXN],wy[MAXN];//每个点的标杆值
int cx[MAXN],cy[MAXN];//每个点匹配的点
int visx[MAXN],visy[MAXN];//每个点是否加入了增广路
int cntx,cnty;//二分图两部分的数量
int mp[MAXN][MAXN];//二分图的权值
int minz=0;//边权和标杆的差的最小值，方便维护
bool dfs(int x)//左边部分的点进入x(数量较少的那一部分)
{
   visx[x]=1;
   for(int y=0;y<cnty;++y)
   {
      if(!visy[y]&&mp[x][y]!=INF)
      {
         int t=wx[x]+wy[y]-mp[x][y];
         if(t==0)//说明为相等子图
         {
            visy[y]=1;//将其加入增广路
            if(cy[y]==-1||dfs(cy[y]))//逻辑同匈牙利
            {
               cx[x]=y;
               cy[y]=x;
               return true;
            }
         }
         else if(t>0)//顶标的和必须大于边权
         {
            minz=min(minz,t);
         }
      }
   }
   return false;
}
int KM()
{
   memset(cx,-1,sizeof(cx));
   memset(cy,-1,sizeof(cy));
   memset(wx,0,sizeof(wx));
   memset(wy,0,sizeof(wy));
   
   for(int i=0;i<cntx;++i)
   {
      for(int j=0;j<cnty;++j)
      {
         if(mp[i][j]==-1)continue;
         wx[i]=max(wx[i],mp[i][j]);//初始化标杆的值为该点所出去的边的最大值
      }
   }
   for(int i=0;i<cntx;++i)//枚举X部分的点
   {
      while(1)
      {
         minz=INF;
         memset(visx,0,sizeof(visx));
         memset(visy,0,sizeof(visy));
         if(dfs(i))break;//匹配正确则跳出
         for(int i=0;i<cntx;++i)if(visx[i])wx[i]-=minz;
         for(int j=0;j<cnty;++j)if(visy[j])wy[j]-=minz;
      }
   }
   int ans=0;
   for(int i=0;i<cntx;++i)
   {
      if(cx[i]!=-1)
      {
         ans+=mp[i][cx[i]];
      }
   }
   return ans;
}
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m=cost.size(),n=cost[0].size();
        vector<int>Lmin(m,INF),Rmin(n,INF);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                Lmin[i]=min(cost[i][j],Lmin[i]);
                Rmin[j]=min(cost[i][j],Rmin[j]);
            }
        }
        ll ans=0;
        for(int i=0;i<m;++i)ans+=Lmin[i];
        for(int j=0;j<n;++j)ans+=Rmin[j];
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                mp[i][j]=max(mp[i][j],Lmin[i]+Rmin[j]-cost[i][j]);
                mp[i][j]=max(mp[i][j],0);
            }
        }
        cntx=m,cnty=n;
        return ans-KM();
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