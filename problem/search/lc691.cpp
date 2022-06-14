/*
    题面：我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。

         您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。

         返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int>dp;
    int n;
    string target;
public:
    int dfs(int now,vector<string>& arr)
    {
        if(dp[now]!=-1)return dp[now];//记忆化搜索
        dp[now]=n+1;
        for(auto& data:arr)
        {
            int pre=now;
            vector<int>tmp(26);
            for(char &c:data)
            {
                tmp[c-'a']++;
            }
            for(int j=0;j<n;++j)
            {
                if((now>>j&1)&&tmp[target[j]-'a']>0)
                {
                    tmp[target[j]-'a']--;
                    pre^=(1<<j);
                }
            }
            if(pre<now)
            {
                dp[now]=min(dp[now],dfs(pre,arr)+1);
            }
        }
        return dp[now];
    }
    int minStickers(vector<string>& stickers, string target) {
        this->n=target.size();
        dp.resize(1<<n,-1);
        dp[0]=0;
        this->target=target;
        int res=dfs((1<<n)-1,stickers);
        return res>n?-1:res;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<string>stickers={"with","example","science"};
  string s="thehat";
  cout<<sol.minStickers(stickers,s);
  return 0;
}