/*
    题意：可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
            'A'：Absent，缺勤
            'L'：Late，迟到
            'P'：Present，到场
            如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：

            按 总出勤 计，学生缺勤（'A'）严格 少于两天。
            学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
            给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n 时，可能获得出勤奖励的记录情况 数量 。答案可能很大，所以返回对 109 + 7 取余 的结果。
    题解：dp[i][j][k]表示前i天，缺勤次数为j次，结尾连续迟到次数为k次且能够得奖的次数
        dp[i][j][k]包括三个部分，即以'A'结尾还有以'P'结尾以及以'L'结尾的次数之和
        1.以A结尾，那么就加上dp[ii][1][k]
        2.以L结尾，那么就加上dp[ii][j][k]
        3.以P结尾，那么要加的最多，都加上就可以了
        注意滚动数组优化空间复杂度

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD=1e9+7;
    using ll=unsigned long long;
public:
    int checkRecord(int n) {
        ll dp[2][2][3];//dp[cur][j][k]表示缺勤j，连续k
        memset(dp,0,sizeof(dp));
        int cur=1,pre=0;
        dp[pre][0][0]=1;
        for(int i=1;i<n;++i)
        {
            cur=i&1,pre=i^1;
            //结尾为A
            for(int k=0;k<3;++k)
            {
                dp[cur][1][0]=(dp[cur][1][0]+dp[pre][0][k])%MOD;//注意这个地方为dp[cur][1][0]因为当前已经确定为A了
            }
            //结尾为L
            for(int j=0;j<2;++j)
            {
                for(int k=1;k<3;++k)
                {
                    dp[cur][j][k]=(dp[cur][j][k]+dp[pre][j][k-1])%MOD;
                }
            }
            //结尾为P
            for(int j=0;j<2;++j)
            {
                for(int k=0;k<3;++k)
                {
                    dp[cur][j][k]=(dp[cur][j][k]+dp[pre][j][k])%MOD;
                }
            }
        }
        ll sum=0;
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<3;++k)
            {
                sum=(sum+dp[cur][j][k])%MOD;
            }
        }
        return sum;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution Sol;
  cout<<Sol.checkRecord(2);
  return 0;
}