#include <bits/stdc++.h>
using namespace std;
const int MAXN=30;
//简单，不需要写板子
struct Edge{
    int u,v,next;
};
Edge E[MAXN];
vector<vector<int>>edges={};
int head[MAXN];
int cnt;
void add_edge(int u,int v)
{
    E[cnt].u=u;
    E[cnt].v=v;
    E[cnt].next=head[u];
    head[u]=cnt++;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   return 0;
}
