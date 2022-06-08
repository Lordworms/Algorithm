#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int MAXN=51;
    static const int CAT_WIN=2;
    static const int MOUSE_WIN=1;
    static const int DRAW=0;
    int dp[MAXN][MAXN][MAXN*(MAXN-1)*2];
    int n;
    vector<vector<int>>graph;
public:
    
    int catMouseGame(vector<vector<int>>& graph) {
        memset(dp,-1,sizeof(dp));
        this->n=graph.size();
        this->graph=graph;
        return getResult(1,2,0);
    }
    int getResult(int mouse,int cat,int turn)
    {
        if(turn==2*n*(n-1))return DRAW;
        if(dp[mouse][cat][turn]<0)
        {
            if(mouse==0)
            {
                dp[mouse][cat][turn]=MOUSE_WIN;
            } 
            else if(mouse==0)
            {
                dp[mouse][cat][turn]=CAT_WIN;
            }       
            else 
            {
                getNextresult(mouse,cat,turn+1);
            }
        }
        return dp[mouse][cat][turn];
    }
    void getNextresult(int mouse,int cat,int turn)
    {
        int curMove=turn%2==0?mouse:cat;
        int pre_result= curMove==cat?MOUSE_WIN:CAT_WIN;
        int result=pre_result;
        for(int next:graph[curMove])
        {
            if(curMove==cat&&next==0)continue;
            int nextMouse= curMove==mouse?next:mouse;
            int nextCat= curMove==cat?next:cat;
            int nextResult=getResult(nextMouse,nextCat,turn+1);
            if(nextResult!=pre_result)
            {
               result=nextResult;
               if(result!=DRAW)
               {
                   break;
               } 
            }
        }
        dp[mouse][cat][turn]=result;
    }

};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    vector<vector<int>>graph={{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}};
    cout<<sol.catMouseGame(graph);
   
   return 0;
}
