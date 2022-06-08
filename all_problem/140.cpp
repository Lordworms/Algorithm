#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,vector<string>>ans;
    unordered_set<string>st;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st={wordDict.begin(),wordDict.end()};
        dfs(0,s);
        return ans[0];
    }
    void dfs(int start,string str)
    {
        if(start==str.size())
        {
            ans[start]={""};
            return;
        }
        ans[start]={};
        for(int i=start+1;i<=str.size();++i)
        {
            string word=str.substr(start,i-start);
            if(st.count(word))
            {
                dfs(i,str);
                for(auto& s:ans[i])
                {
                    ans[start].push_back(s.empty()?word:(word+" "+s));
                }
            }
        }
    }
};
int main()
{
    Solution a;
    vector<string>dic={"cat","cats","and","sand","dog"};
    vector<string>k=a.wordBreak("catsanddog",dic);

    return 0;
}