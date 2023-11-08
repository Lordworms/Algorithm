/*
    给你两个整数 num 和 k ，考虑具有以下属性的正整数多重集：

    每个整数个位数字都是 k 。
    所有整数之和是 num 。
    返回该多重集的最小大小，如果不存在这样的多重集，返回 -1 。

    注意：
    多重集与集合类似，但多重集可以包含多个同一整数，空多重集的和为 0 。
    个位数字 是数字最右边的数位。
    题解：
        枚举开头和+的部分，每次更新答案即可
        if(j%10==k)
            dp[i+j]=min(dp[i+j],dp[i]+1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumNumbers(int num, int k) {
        int dp[3001];
        memset(dp,0x3f3f33f,sizeof(dp));
        dp[0]=0;
        for(int i=0;i<num;++i)
        {
            for(int j=0;j+i<=num;++j)
            {
                if(j%10==k)
                {
                    dp[i+j]=min(dp[i+j],dp[i]+1);
                }
            }
        }
        return dp[num]>num?-1:dp[num];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   Solution Sol;
   cout<<Sol.minimumNumbers(58,9);
  return 0;
}