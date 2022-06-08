#include <bits/stdc++.h>
using namespace std;
//判定一个图是否为二分图
vector<vector<int>>G;
vector<int>color;
int E,V;

bool dfs(int x,int c)
{
    color[x]=c;
    for(int y:G[x])
    {
        if(color[y]==c)return false;
        if(!color[y]&&!dfs(y,-c))return false;
    }
    return true;
}
bool check()
{
    for(int i=0;i<V;++i)
    {
       if(!color[i]&&!dfs(i,1))
       {
           return false;
       }
    }
    return true;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int x,y;
   cin>>E>>V;
   color.resize(V,0);
   for(int i=0;i<E;++i)
   {
       cin>>x>>y;
       G[x].push_back(y);
       G[y].push_back(x);
   }
    cout<<check()<<endl;
   
   return 0;
}
