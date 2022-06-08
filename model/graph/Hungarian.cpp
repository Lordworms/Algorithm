#include <bits/stdc++.h>
using namespace std;
const int MAXN=300;
vector<int>boys,girls;
bool vis[MAXN][MAXN];
vector<bool>used;
//匈牙利算法求二分图最大匹配//满足图为二分图
int n,m;//男性和女性的数量
bool find(int x)
{
   for(int i=0;i<m;++i)
   {
      if(vis[x][i]&&!used[i])//有一条边并且没有被使用过
      {
         used[i]=true;
         if(girls[i]==0||find(girls[i]))//还未配对或者可以离婚做前夫
         {
            girls[i]=x;
            return true;
         }
      }
   }
   return false;
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int ans=0;
   for(int i=0;i<n;++i)
   {
      if(find(i))
      {
         ++ans;
      }
   }
   
   return 0;
}
