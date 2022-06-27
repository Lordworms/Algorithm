/*
题意：
    给你两个正整数 n 和 k 。
    如果正整数 i 满足 n % i == 0 ，那么我们就说正整数 i 是整数 n 的因子。
    考虑整数 n 的所有因子，将它们 升序排列 。请你返回第 k 个因子。如果 n 的因子数少于 k ，请你返回 -1 。
题解：考察有n/i为因子，那么就有i为因子，所以我们枚举根号下n的因子即可
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthFactor(int n, int k) {
        int i;
        for(i=1;i*i<=n;++i)
        {
            if(n%i==0)
            {
                if(--k==0)return i;
            }
        }
        --i;
        for(i=(i*i==n?i-1:i);i>0;--i)
        {
            if(n%i==0)
            {
                if(--k==0)return n/i;
            }
        }
        return -1;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}