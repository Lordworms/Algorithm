#include<bits/stdc++.h>
using namespace std;
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        unordered_set<string>dic;
        for(auto str:wordDict)
        {
            dic.insert(str);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(dp[j]&&dic.find(s.substr(j,i-j))!=dic.end())
                {
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
int main()
{
    vector<string>a={"leet","code"};
    string s="leetcode";
    cout<<wordBreak(s,a);
}