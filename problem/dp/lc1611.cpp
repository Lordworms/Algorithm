/*
题意：给你一个整数 n，你需要重复执行多次下述操作将其转换为 0 ：
     翻转 n 的二进制表示中最右侧位（第 0 位）。
     如果第 (i-1) 位为 1 且从第 (i-2) 位到第 0 位都为 0，则翻转 n 的二进制表示中的第 i 位。
     返回将 n 转换为 0 的最小操作次数。
题解：dp1[i]表示把第i位从1变成0的操作次数，dp2[i]表示从0-i位都是1的时候的最小操作次数
    dp1[i]=dp1[i-1]+1+dp2[i-1];
    dp2[i]=dp2[i-1]+1+dp1[i-1];
    用dp[i]表示把第i及其之后的位都变成0的最小操作次数
    随后由于dp1[i]包含了把之后的位变成0的操作，所以得减去后续的dp部分
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int sym=1;
        int ans=0;
        vector<long>dp1(32,0),dp2(32,0);
        dp1[0]=dp2[0]=1;
        for(int i=1;i<=31;--i)
        {
            dp1[i]=dp1[i-1]+1+dp2[i-1];
            dp2[i]=dp1[i-1]+1+dp2[i-1];
        }
        for(int i=31;i>=0;--i)
        {
            if((n>>i)&1)
            {
                ans+=(sym*dp1[i]);
                sym=-sym;
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
return 0;
}