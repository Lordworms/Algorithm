/*
给你一个字符串 s 和一个机器人，机器人当前有一个空字符串 t 。执行以下操作之一，直到 s 和 t 都变成空字符串：

删除字符串 s 的 第一个 字符，并将该字符给机器人。机器人把这个字符添加到 t 的尾部。
删除字符串 t 的 最后一个 字符，并将该字符给机器人。机器人将该字符写到纸上。
请你返回纸上能写出的字典序最小的字符串。
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<char>f(n+1,'z');
        for(int i=n-1;i>=0;--i)f[i]=min(f[i+1],s[i]);
        string st,ans;
        for(int i=0;i<n;++i)
        {
           st.push_back(s[i]);
           while(st.size()&&st.back()<=f[i+1])ans.push_back(st.back()),st.pop_back();
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.robotWithString("bdwdadwmdw");
  return 0;
}