/*
    题面：求一个字符串中回文子序列的个数
    
    
    我们用dp[i][j]表示从i到j区间内的不同回文序列的个数
    dp[i][j]=2*dp[i+1][j-1]+2 //s[i]==s[j]=x&&low>high//low>high 表示区间内没有相同点，这种情况直接拓展
            =2*dp[i+1][j-1]+1//s[i]==s[j]=x&&low==high//区间内有一个相同点，此时减去这种情况重复计算的一个回文子串
            =2*dp[i+1][j-1]-dp[low+1][high-1]//low<high&&s[i]==s[j] 区间内有两个相同点，此时重复计算的就是包含在这两个区间内的，减去即可
            =dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];//两侧都不相等，此时只能分别计算（加上i的+加上j的-重复计算的）
            
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD=1e9+7;
    typedef long long ll;
public:
    int countPalindromicSubsequences(string s) {
        int n=s.size();
        vector<vector<ll>>dp(n,vector<ll>(n,0));
        for(int i=0;i<n;++i)
        {
            dp[i][i]=1;
        }
        vector<int>pos(4,-1);
        vector<vector<int>>pre(n,vector<int>(4,-1));
        vector<vector<int>>next(n,vector<int>(4,n));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<4;++j)
            {
                pre[i][j]=pos[j];
            }
            pos[s[i]-'a']=i;
        }
        pos[0]=pos[1]=pos[2]=pos[3]=n;
        for(int i=n-1;i>=0;--i)
        {
            for(int j=0;j<4;++j)
            {
                next[i][j]=pos[j];
            }
            pos[s[i]-'a']=i;
        }
        for(int len=2;len<=n;++len)//区间dp的模版for循环
        {
            for(int i=0;i+len<=n;++i)
            {
                int j=i+len-1;
                if(s[i]==s[j])
                {
                    int low=next[i][s[i]-'a'];
                    int high=pre[j][s[j]-'a'];
                    if(high==low)dp[i][j]=(2*dp[i+1][j-1]+1)%MOD;//只有一个点相等
                    else if(low>high)dp[i][j]=(2*dp[i+1][j-1]+2)%MOD;//没有点相等
                    else dp[i][j]=(2*dp[i+1][j-1]-dp[low+1][high-1]+MOD)%MOD;//有两个点相等
                }
                else
                {
                    dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+MOD)%MOD;
                }
            }
        }
        return dp[0][n-1];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.countPalindromicSubsequences("bccb");
  return 0;
}