/*
题意：
    给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。
题解：均值不等式板子题
    首先肯定是每个数都相等的时候乘积最大，那么我们枚举每一个因子，然后判断是否有余数，那么此时有两种情况，第一种为直接乘上这个余数，第二个是把这个余数和其中一个因子相加
    了再乘，分别对比即可
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    int quickPow(int base,int exp)
    {
        int ans=1;
        while(exp)
        {
            if(exp&1)ans*=base;
            base*=base;
            exp>>=1;
        }
        return ans;
    }
    int integerBreak(int n) {
        if(n<=3)return n-1;
        int ans=INT_MIN;
        for(int i=1;i<=(n+1)/2;++i)
        {
            int div=n/i;
            int remain=n-div*i;
            if(remain)
            {
                ans=max(ans,max(quickPow(i,div)*remain,quickPow(i,div-1)*(i+remain)));
            }
            else
            {
                ans=max(ans,quickPow(i,div));
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.integerBreak(10);
return 0;
}