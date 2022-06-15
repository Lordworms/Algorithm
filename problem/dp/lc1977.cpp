/*
    题面：你写下了若干 正整数 ，并将它们连接成了一个字符串 num 。但是你忘记给这些数字之间加逗号了。你只记得这一列数字是 非递减 的且 没有 任何数字有前导 0 。

请你返回有多少种可能的 正整数数组 可以得到字符串 num 。由于答案可能很大，将结果对 109 + 7 取余 后返回。
    题解：
        用dp[i][j]表示从当前在i位置，且上一个划分的数字长度为j的解数量，那么上一个位置为i-j，那么答案很显然，就是
        dp[i-j][k](k<=j)的和，我们知道，在k<j的情况下，前一个数字一定小于后一个数，那么我们考虑在k==j的情况，这种情况下
        我们需要遍历两个子字符串得到结果，在极端情况下很低效
        因此，我们需要预处理出一样东西，c[i][j]表示从i和j开头的数字，i不大于j的最小长度
        容易得出c[i][j]= num[i]==num[j]?(c[i+1][j+1]):(num[i]>num[j]?0:len(stri)<len(strj)):
        注意这里的下标最小为2，因为你需要计算dp[1-2]当下标为1的时候，这个时候其实你的长度已经为2了，再减下去会越界
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD=1e9+7;
    using ll=long long;
    int n;
public:
    int numberOfCombinations(string num) {
        n=num.size();
        if(num[0]=='0')return 0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<vector<int>>c(n,vector<int>(n,0));
        dp[1]=vector<int>(n+1,1);
        dp[1][0]=0;
        for(int len=1;len<=n;++len)
        {
            for(int i=n-1-len;i>=0;--i)
            {
                if(num[i]<num[i+len])
                {
                    c[i][i+len]=n-i-len;
                }
                else if(num[i]==num[i+len])
                {
                    if(i+len==n-1)c[i][i+len]=1;
                    else c[i][i+len]=c[i+1][i+len+1]+1;
                }
            }
        }
        auto cmp=[&](int l,int r,int len){
          if(l<0)return false;
          return c[l][r]>=len;  
        };
        for(int i=2;i<=n;++i)
        {
            dp[i][i]=1;
            for(int j=1;j<=i;++j)
            {
                if(num[i-j]=='0')
                    continue;
                if(cmp(i-2*j,i-j,j))
                    dp[i][j]=(dp[i][j]+dp[i-j][j])%MOD;
                else 
                    dp[i][j]=(dp[i][j]+dp[i-j][j-1])%MOD;
            }
            for(int j=1;j<=n;++j)
            {
                dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
            }
        }
        return dp[n][n];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.numberOfCombinations("999");
  return 0;
}