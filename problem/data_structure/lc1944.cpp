/*
题意：有 n 个人排成一个队列，从左到右 编号为 0 到 n - 1 。给你以一个整数数组 heights ，每个整数 互不相同，heights[i] 表示第 i 个人的高度。

一个人能 看到 他右边另一个人的条件是这两人之间的所有人都比他们两人 矮 。更正式的，第 i 个人能看到第 j 个人的条件是 i < j 且 min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]) 。

请你返回一个长度为 n 的数组 answer ，其中 answer[i] 是第 i 个人在他右侧队列中能 看到 的 人数 
题解：单调栈，因为是向右看，所以从后向前遍历即可
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;--i)
        {
            while(!st.empty()&&heights[st.top()]<heights[i])
            {
                ans[i]++;
                st.pop();
            }
            ans[i]+=(st.size()>0);
            st.push(i);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>heights={5,1,2,3,10};
  sol.canSeePersonsCount(heights);
  return 0;
}