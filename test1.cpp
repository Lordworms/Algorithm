#include <bits/stdc++.h>
using namespace std;
vector<bool>vis;
vector<vector<int>>newG;
bool ans=false;
void dfs(int now,int fa)
{
    vis[now]=true;
    for(int nxt:newG[now])
    {
       if(vis[nxt]==true&&nxt!=fa){ans=false;return;}
       dfs(nxt,now);
    }
}
bool solution(int n, vector<vector<int>> g, vector<int> v) {
   unordered_set<int>st;
   for(int p:v)st.insert(p);
   newG.resize(n+1);
   vis.resize(n+1,false);
   vector<int>in(n+1,0);
   for(auto edge:g)
   {
       if(st.count(edge[0])&&!st.count(edge[1])){newG[v[0]].push_back(edge[1]);in[edge[1]]++;}
       else if(st.count(edge[1])&&!st.count(edge[0])){newG[edge[0]].push_back(v[0]);in[v[0]]++;}
       else if(st.count(edge[1]&&st.count(edge[0])))continue;
       else {newG[edge[0]].push_back(edge[1]);in[edge[1]]++;}
   }
   int now;
   for(int i=1;i<=n;++i)
   {
       if((st.count(i)&&in[v[0]])||in[i])continue;
       now=st.count(i)?v[0]:i;
       break;
   }
   dfs(now,0);
   return ans?false:true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>>G={{1, 2}, {2, 3}, {2, 4}, {2, 5}, {4, 6}, {5, 6}};
  solution(6,G,{1,2,4});
  return 0;

}