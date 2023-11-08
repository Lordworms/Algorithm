/*
    题意：给你一个二进制字符串 s 和一个正整数 k 。
        请你返回 s 的 最长 子序列，且该子序列对应的 二进制 数字小于等于 k 。
        注意：
        子序列可以有 前导 0 。
        空字符串视为 0 。
        子序列 是指从一个字符串中删除零个或者多个字符后，不改变顺序得到的剩余字符序列。
    题解：
        先选择所有的0，然后从低位到高位选择所有的1，直到当前值大于k
        这是由于低位的1比高位的1优先级更高的缘故
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        using ll=unsigned long long;
        const int INF=1e9;
        ll val=0;
        int len=0;
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i]=='0')//无脑加
            {
                ++len;
            }
            else 
            {
                if(val+((ll)1<<len)>k)continue;
                if(val+((ll)1<<len)>1e9)return len;
                val+=(1<<len);
                len+=1;
            }
        }
        return len;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.longestSubsequence("1001010",5);
  return 0;
}