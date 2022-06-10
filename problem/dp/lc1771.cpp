#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string mod=word1+word2;
        int l=word1.size(),r=word2.size();
        int n=mod.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i)dp[i][i]=1;
        for(int i=0;i<n-1;++i)dp[i][i+1]=(mod[i]==mod[i])?2:1;
        int ans=0;
        for(int i=n-2;i>=0;--i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(mod[i]==mod[j])
                {
                    if(j-i>1)dp[i][j]=max(dp[i][j],dp[i+1][j-1]+2);
                    if(i<l&&j>=l)ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
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
  cout<<sol.longestPalindrome("aa","bb");
  return 0;
}