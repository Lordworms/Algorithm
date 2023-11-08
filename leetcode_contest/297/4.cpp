/*
  题面：给你一个字符串数组 ideas 表示在公司命名过程中使用的名字列表。公司命名流程如下：
        从 ideas 中选择 2 个 不同 名字，称为 ideaA 和 ideaB 。
        交换 ideaA 和 ideaB 的首字母。
        如果得到的两个新名字 都 不在 ideas 中，那么 ideaA ideaB（串联 ideaA 和 ideaB ，中间用一个空格分隔）是一个有效的公司名字。
        否则，不是一个有效的名字。
        返回 不同 且有效的公司名字的数目。
    题解：
        首先我们要清楚，要怎么存这些字符串，我们可以用一个unordered_map<char,vector<string>>来存这些字符串的首字母和之后的对应关系
        之后我们遍历所有的起始位置的字符，那么产生的新字符串的个数为(mp[i]-cnt)*(mp[j]-cnt)*2,其中cnt为这两个首字母之后的字符串相等的个数。
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char,unordered_set<string>>mp;
        for(auto& s:ideas)
        {
            mp[s[0]].insert(s.substr(1));
        }
        int ans=0;
        for(char i='a';i<='z';++i)
        {
          if(mp.find(i)==mp.end())continue;
          for(char j=i+1;j<='z';++j)
          {
            if(mp.find(j)==mp.end())continue;
              int cnt=0;
            for(auto& s:mp[i])
            {
              if(mp[j].count(s))
              {
                  cnt++;
              }
            }
            ans+=(mp[i].size()+mp[j].size()-2*cnt);
          }
        }          
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  
  return 0;
}