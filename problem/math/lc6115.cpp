/*
题意：
    给你两个整数 n 和 maxValue ，用于描述一个 理想数组 。
    对于下标从 0 开始、长度为 n 的整数数组 arr ，如果满足以下条件，则认为该数组是一个 理想数组 ：
    每个 arr[i] 都是从 1 到 maxValue 范围内的一个值，其中 0 <= i < n 。
    每个 arr[i] 都可以被 arr[i - 1] 整除，其中 0 < i < n 。
    返回长度为 n 的 不同 理想数组的数目。由于答案可能很大，返回对 109 + 7 取余的结果。
题解：
    我们考虑maxvalue为2的一个序列其肯定为
    1 1 1 . . . .2  2 2 2 2
    那么肯定为在某些位置处我们放置了一个质因子，根据这个性质，我们只需要知道，我们一共有多少种不同的存放质因子的方式就好了
    这就转化为了一个组合数学问题，我们在n个位置放置k个质因子
    这里我们用隔板法来做，也就是说，我们把
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MAXN=1e4+15;
        const int MK=14;
        const int MOD=1e9+7;
        vector<vector<int>>C(MAXN+1,vector<int>(MK+1,0));//组合数
        vector<int>ks[MAXN];//ks[i]表示i的每个质因子分别有多少个，例如12的话ks[12][0]=2(2个2) ks[12][1]=1(1个3)
        auto init=[&](){
            for(int i=0;i<MAXN;++i)
            {
                for(int j=0;j<=min(i,MK);++j)
                {
                    if(j==0)C[i][j]=1;
                    else C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
                }
            }
            for(int i=2;i<MAXN;++i)
            {
                int x=i;
                for(int p=2;p*p<=x;++p)
                {
                    if(x%p==0)
                    {
                        int k=0;
                        for(;x%p==0;x/=p)++k;
                        ks[i].push_back(k);
                    }
                }
                if(x>1)ks[i].push_back(1);
            }
        };
        init();
        long ans=0;
        for(int i=1;i<=maxValue;++i)
        {
            long mul=1;
            for(int k:ks[i])mul=mul*C[n+k-1][k]%MOD;
            ans=ans+mul%MOD;
        }
        return ans%MOD;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.idealArrays(10000,10000);
  return 0;
}