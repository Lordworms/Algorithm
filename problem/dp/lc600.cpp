/*
    题意：给定一个正整数 n ，返回范围在 [0, n] 都非负整数中，其二进制表示不包含 连续的 1 的个数。
    题解:数字的范围在1e9，所以不可能遍历n来做,这是一道数位dp的板子题
        另dp[i]表示在以0为根的0-1字典树中，其高度为i-1没有连续1的数字的个数
        dp[i]=dp[i-1]+dp[i-2]其中dp[i-1]表示其左子树，dp[i-2]表示其右子树的左子树
        然后我们倒序遍历，每次
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findIntegers(int n) {
        int dp[31];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<31;++i)dp[i]=dp[i-1]+dp[i-2];
        int pre=0,cur=0;
        int ans=0;
        for(int i=29;i>=0;--i)
        {
          int v=(1<<i);
          if(n&v)
          {
            ans+=dp[i+1];
            if(pre==1)break;
            pre=1;
          }
          else
          {
            pre=0;
          }
          if(i==0)ans++;
        }
      return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution Sol;
  cout<<Sol.findIntegers(5);
  return 0;
}