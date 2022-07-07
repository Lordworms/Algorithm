/*
题意：给你一个只包含小写英文字母的字符串 s 。

每一次 操作 ，你可以选择 s 中两个 相邻 的字符，并将它们交换。

请你返回将 s 变成回文串的 最少操作次数 。

注意 ，输入数据会确保 s 一定能变成一个回文串。
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0,j=n-1;i<j;++i)
        {
            bool flag=false;
            for(int k=j;k>i;--k)
            {
                if(s[k]==s[i])
                {
                    for(;k<j;++k)
                    {
                        ++ans;
                        swap(s[k],s[k+1]);
                    }
                    flag=true;
                    --j;
                    break;
                }
            }
           
            if(!flag)ans+=n/2-i;
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.minMovesToMakePalindrome("aabb");
  return 0;
}