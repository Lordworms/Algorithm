#include <bits/stdc++.h>
using namespace std;
//为KM算法的实现，KM算法是求二分图的完美匹配，也就是在匈牙利算法的基础上，每条边有边权了，要求这个匹配的最大/最小边权和
//时间复杂度O（n^4）
const int MAXN=400;
typedef long long ll;
const int INF=0x3f3f3f3f;
int wx[MAXN],wy[MAXN];//每个点的标杆值
int cx[MAXN],cy[MAXN];//每个点匹配的点
int visx[MAXN],visy[MAXN];//每个点是否加入了增广路
int cntx,cnty;//二分图两部分的数量
int mp[MAXN][MAXN];//二分图的权值
int minz;//边权和标杆的差的最小值，方便维护
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
void sol()
{
   memset(mp,-1,sizeof(mp));
   cntx=cnty=4;
   vector<vector<int>>w={{62,41,86,94},{73,58,11,12},{69,93,89,88},{81,40,69,13}};
   for(int i=0;i<cntx;++i)
   {
      for(int j=0;j<cnty;++j)
      {
         mp[i][j]=w[i][j];
      }
   }
   cout<<KM()<<endl;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   sol();
   return 0;
}
