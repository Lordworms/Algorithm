/*
   题面：给你一个字符串 s ，如果可以将它分割成三个 非空 回文子字符串，那么返回 true ，否则返回 false 。

当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。

   题解：又是一道区间dp题，首先我们先预处理其中任意两个点组成的串是否为回文串，之后我们枚举两个端点，判断是否可以组成回文串，简单题
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPartitioning(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;++i)dp[i][i]=true;
        for(int i=n-2;i>=0;--i)
        {
            for(int j=i+1;j<n;++j)
            {
                dp[i][j]=(s[i]==s[j])&(dp[i+1][j-1]||(j-i==1));
            }
        }
        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j<n-1;++j)
            {
                if(dp[0][i]&&dp[i+1][j]&&dp[j+1][n-1])return true;
            }
        }
        return false;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.checkPartitioning("bcbddxy");
  return 0;
}