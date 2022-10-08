/*
题意：
给你一个仅由小写英文字母组成的字符串 s 。在一步操作中，你可以：

删除 整个字符串 s ，或者
对于满足 1 <= i <= s.length / 2 的任意 i ，如果 s 中的 前 i 个字母和接下来的 i 个字母 相等 ，删除 前 i 个字母。
例如，如果 s = "ababc" ，那么在一步操作中，你可以删除 s 的前两个字母得到 "abc" ，因为 s 的前两个字母和接下来的两个字母都等于 "ab" 。

返回删除 s 所需的最大操作数。

题解：对任意两个后缀，求lcp，然后dp
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteString(string s) {
        vector<vector<int>>lca(s.size(),vector<int>(s.size(),0));
        int n=s.size();
        for(int i=n-1;i>=0;--i)
        {
            for(int j=n-1;j>=0;--j)
            {
                if(s[i]==s[j])
                {
                    lca[i][j]=1;
                    if(i<n-1&&j<n-1)
                    {
                        lca[i][j]+=lca[i+1][j+1];
                    }
                }
            }
        }
        vector<int>dp(n);
        for(int i=n-1;i>=0;--i)
        {
            dp[i]=1;
            for(int j=1;j<=(n-i)/2;++j)
            {
                if(lca[i][i+j]>=j)
                {
                    dp[i]=max(dp[i],dp[i+j]+1);
                }
            }
        }
        return dp[0];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  return 0;
}