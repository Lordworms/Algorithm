#include<bits/stdc++.h>
using namespace std;

int solution(string s,string p)
{
    int n=s.size(),m=p.size();
    s=' '+s;p=' '+p;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    for(int j=1;j<=m;++j)
    {
        if(p[j]=='*')dp[0][j]=dp[0][j-2];
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(p[j]=='*'){
                if(p[j-1]=='.'||s[i]==p[j-1])
                    dp[i][j]=dp[i-1][j];
                dp[i][j]|=dp[i][j-2];
            }
            else if(p[j]==s[i]||p[j]=='.')
            {
                dp[i][j]=dp[i-1][j-1];
            }
        }
    return dp[n][m];
}
int main()
{
    cout<<solution("aaaaaaa",".*");
}