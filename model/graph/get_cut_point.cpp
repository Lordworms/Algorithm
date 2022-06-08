#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+9;
int times=0;
int dfn[MAXN],low[MAXN],is_cut[MAXN];
vector<vector<int>>edges;
vector<vector<int>>rec;
//求割点，时间复杂度为O(E+V)
void get_slide_point(int now,int fa)
{
    int child=0;
    dfn[now]=low[now]=++times;
    for(auto& next:rec[now])
    {
        if(!dfn[next])//未被访问过
        {
            ++child;
            get_slide_point(next,now);
            low[now]=min(low[now],low[next]);
            if(low[next]>=dfn[now])
            {
                is_cut[now]=true;
            }
        }
        else if(dfn[next]<dfn[now]&&next!=fa)//被访问过且不为祖先
        {
            low[now]=min(low[now],dfn[next]);
        }
    
    }
    if(fa==-1&&child==1)
    {
        is_cut[now]=false;
    }
}


int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   
   return 0;
}
