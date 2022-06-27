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
    const int MOD=1e9+7;
    vector<int>c;
    int lowbit(int x){return x&(-x);}
    int sum(int x){
        int ans=0;
        while(x)
        {
          ans+=c[x];
          x-=lowbit(x);
        }
        return ans;
    }
    int createSortedArray(vector<int>& instructions) {
        int n=100010;
        c.resize(n);
        int ans=0;
        for(int num:instructions)
        {
            int pre=sum(num-1),next=sum(n-1)-sum(num);
            ans+=min(pre,next);
            ans%=MOD;
            while(num<1e5+5){c[num]++;num+=lowbit(num);}
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>arr={1,2,3,6,5,4};
  cout<<sol.createSortedArray(arr);
  return 0;
}