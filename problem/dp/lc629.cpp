/*
    题面：给出两个整数 n 和 k，找出所有包含从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数。

        逆序对的定义如下：对于数组的第i个和第 j个元素，如果满i < j且 a[i] > a[j]，则其为一个逆序对；否则不是。

        由于答案可能很大，只需要返回 答案 mod 109 + 7 的值。
    
    题解：区间dp的经典题，首先我们用dp[i][j]表示前i个数字含有j个逆序对的不同数组的个数
         我们对于一个序列1 2 3 ..... k-1 k k+1......i这个序列，我们考虑k这个数对于逆序对的贡献
         分为两个部分，第一个是k+1.....i这i-k个数组成的逆序对
                     第二个是i-1个元素内部产生的逆序对
        第一个部分共有i-k个，对于第二个部分，我们希望他有j-i+k个，这样才能满足j个
        所以我们得到了转移方程dp[i][j]=求和：dp[i-1][j-i+k](k=[1,i])=求和dp[i-1][j-k](k=[0,i-1])
        dp[i][j-1]=求和dp[i-1][j-k-1](k=[0,i-1])
        所以dp[i][j]=dp[i][j-1]-dp[i-1][j-i]+dp[i-1][j]
        后半部分已经计算出来了，然后我们用滚动数组节省空间复杂度
        (学会基本的滚动数组思路，以及MOD某个数的时候的操作)

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD=1e9+7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(2,vector<int>(k+1,0));
        dp[0][0]=1;
        int cur,pre;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=k;++j)
            {
                cur=i&1,pre=cur^1;
                dp[cur][j]=(j>0?dp[cur][j-1]:0)-(j>=i?dp[pre][j-i]:0)+dp[pre][j];
                if(dp[cur][j]>MOD)
                {
                    dp[cur][j]-=MOD;
                }
                else if(dp[cur][j]<0)
                {
                    dp[cur][j]+=MOD;
                }
            }
        }
        return dp[n&1][k];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}