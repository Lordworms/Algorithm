/*
题意：给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的 花期 从 starti 到 endi （都 包含）。同时给你一个下标从 0 开始大小为 n 的整数数组 persons ，persons[i] 是第 i 个人来看花的时间。

请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目 。
题解：经典的拆点题，把starti拆成[start,+1],[end,-1],然后排序即可,记得要先开花，所以[flower[0],INF]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<pair<int,int>>arr;
        const int INF=INT_MAX;
        for(auto& flower:flowers)
        {
            arr.push_back(pair<int,int>(flower[0],-INF));
            arr.push_back(pair<int,int>(flower[1],INF));
        }
        for(int i=0;i<persons.size();++i)arr.push_back(pair(persons[i],i));
        vector<int>ans(persons.size());
        sort(arr.begin(),arr.end());
        int now=0;
        for(auto& a:arr)
        {
            if(a.second==INF)
            {
                --now;
            }
            else if(a.second==-INF)
            {
                ++now;
            }
            else
            {
                ans[a.second]=now;
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
  vector<vector<int>>arr{{1,6},{3,7},{9,12},{4,13}};
  vector<int>b={2,3,7,11};
  sol.fullBloomFlowers(arr,b);
  return 0;
}