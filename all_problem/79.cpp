#include<bits/stdc++.h>
using namespace std;
    int ans=0;
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>&board,vector<vector<int>>&vis,int i,int j,int now,string& word)
    {
        if(now==word.size()-1)
        {
            ans=1;
            return;
        }
        vis[i][j]=1;
        for(int k=0;k<4;++k)
        {
            int now_i=i+dir[k][0];
            int now_j=j+dir[k][1];
           
            if(now_i<vis.size()&&now_i>=0&&now_j<vis[0].size()&&now_j>=0&&vis[now_i][now_j]==0&&board[now_i][now_j]==word[now])
            {
                
                vis[now_i][now_j]=1;
                dfs(board,vis,now_i,now_j,now+1,word);
                vis[now_i][now_j]=0;
            }
        }
    }
bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if(board[i][j]==word[0])
                {
                    if(word.size()==1)return true;
                    dfs(board,vis,i,j,1,word);
                }
            }
        
        if(ans==0)return false;
        return true;
}
int main()
{
    vector<vector<char>>map={{'A','B','C','E'},{'S','F','C','S'},{'A','D','F','E'}};
    cout<<exist(map,"ABCCED");
}