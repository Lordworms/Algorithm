/*
    题意:在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

        给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。

        当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。

        另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj, colj] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。

        返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。

    题解:两条对角线分别为x+y和x-y，注意存pair的擦耦哦

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int,int>row,col,pcross,ncross;
public:
     bool check(int i,int j)
    {
        return row.count(i)&&row[i]>0||col.count(j)&&col[j]>0||pcross.count(i-j)&&pcross[i-j]>0||ncross.count(i+j)&&ncross[i+j]>0;
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        auto hash_p=[](const pair<int,int>&p)->size_t{
        static hash<long long>hashll;
        return hashll(p.first+(static_cast<long long>((p.second))<<32));
    };
        unordered_set<pair<int,int>,decltype(hash_p)>st(0,hash_p);
        for(auto& lamp:lamps)
        {
            if(st.count({lamp[0],lamp[1]}))continue;
            row[lamp[0]]++;//对应行++
            col[lamp[1]]++;//对应列++
            pcross[lamp[0]-lamp[1]]++;
            ncross[lamp[0]+lamp[1]]++;
            st.insert({lamp[0],lamp[1]});
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();++i)
        {
            auto& q=queries[i];
            if(check(q[0],q[1]))ans[i]=1;
            for(int x=q[0]-1;x<=q[0]+1;++x)
            {
                for(int y=q[1]-1;y<=q[1]+1;++y)
                {
                    if(x<0||x>=n||y<0||y>=n)continue;
                    auto p=st.find({x,y});
                    if(p!=st.end())
                    {
                        st.erase(p);
                        row[x]--;
                        col[y]--;
                        pcross[x-y]--;
                        ncross[x+y]--;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<vector<int>>q={{0,0},{4,4}};
  vector<vector<int>>l={{1,1},{1,0}};
  sol.gridIllumination(5,q,l);
  return 0;
}