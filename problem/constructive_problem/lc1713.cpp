/*
题意：给你一个数组 target ，包含若干 互不相同 的整数，以及另一个整数数组 arr ，arr 可能 包含重复元素。

每一次操作中，你可以在 arr 的任意位置插入任一整数。比方说，如果 arr = [1,4,1,2] ，那么你可以在中间添加 3 得到 [1,4,3,1,2] 。你可以在数组最开始或最后面添加整数。

请你返回 最少 操作次数，使得 target 成为 arr 的一个子序列。
题解：很容易读懂题意，就是求最长公共子序列的长度，然后用target的长度减去这个长度
    可以将其离散化，然后转化为求最长上升子序列的长度，可以用二分来加速，最终复杂度为m+nlogn

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        int m=arr.size(),n=target.size();
        unordered_map<int,int>st;
        for(int i=0;i<n;++i)
        {
            st[target[i]]=i;
        }
        vector<int>d;
        for(int& num:arr)
        {
            if(st.count(num))
            {
                auto it=lower_bound(d.begin(),d.end(),st[num]);
                if(it==d.end())
                {
                    d.push_back(st[num]);
                }
                else
                {
                    *it=st[num];
                }
            }
        }
        return n-d.size();
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>a={3,1,4,2,5,2,6,1};
  sol.minOperations(a,a);
  return 0;
}