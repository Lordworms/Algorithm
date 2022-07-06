/*
题意：给出两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为子序列的最短字符串。如果答案不止一个，则可以返回满足条件的任意一个答案。

（如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 任意位置），可以得到字符串 S，那么 S 就是 T 的子序列）
题解：采用lcq的一般计算方式，先计算lcq，然后对应进行第二次遍历，每次如果a[i]==b[j],那么说明这俩push一个进来即可
    否则，我们分情况进行讨论，对于dp[i][j]=dp[i][j-1]说明b[j]没有起到任何作用，那么把b[j]弄进来
    否则把a[i]弄进来
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        str1.insert(0," ");
        str2.insert(0," ");
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(str1[i]==str2[j])
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        int i=m,j=n;
        string ans;
        while(i||j)
        {
            if(!j)ans+=str1[i--];
            else if(!i)ans+=str2[j--];
            else{
                if(str1[i]==str2[j])//这俩相等，说明只需要弄一个进来即可
                {
                    ans+=str1[i--],--j;
                }
                else
                {
                    if(dp[i][j]==dp[i-1][j])ans+=str1[i--];//说明i不影响长度
                    else ans+=str2[j--];
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};  
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  
  //"bbabaaababb"
  cout<<sol.shortestCommonSupersequence("abab","cab");
  return 0;
}