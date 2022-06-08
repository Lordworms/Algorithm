#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e9+7;
int low[MAXN],dfn[MAXN];
vector<vector<int>>rec;
vector<vector<int>>edges={{0,1},{1,2},{2,0},{1,3}};
int n=4;
stack<int>s;
vector<int>ans;
void tarjan(int now)
{
    for(auto& num:rec[now])
    {
        
    }

}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   rec.resize(n);
   for(auto& edge:edges)
   {
       rec[edge[0]].push_back(edge[1]);
       rec[edge[1]].push_back(edge[0]);
   }
   for(int i=0;i<n;++i)
   {
       if(!dfn[i])
       {
           tarjan(i);
       }
   }
   return 0;
}
