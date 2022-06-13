/*
    题面：给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回 所有 能够得到 target 的表达式。
         注意，返回表达式中的操作数 不应该 包含前导零。



*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    typedef unsigned long long ll;
    int n;
    string tmp;
    int com;
    vector<string>ans;
public:
    void dfs(string& num,int & target,int pos,ll val)
    {
        if(pos==n)
        {
            if(val==target)ans.push_back(tmp);
            return;
        }
        for(int i=0;i<3;++i)
        {
            if(i==0)
            {
                tmp.push_back('+'),tmp.push_back(num[pos]);
                com+=(num[pos]-'0');
                dfs(num,target,pos+1,val+com);
            }
            else if(i==2)
            {
                tmp.push_back('-'),tmp.push_back(num[pos]);
                com=-num[pos];
                dfs(num,target,pos+1,val+com);
            }
            else
            {
                tmp.push_back('*'),tmp.push_back(num[pos]);
                com*=(num[pos]-'0');
                dfs(num,target,pos+1,val+com);
            }
            tmp.pop_back(),tmp.pop_back();
        }
    }
    vector<string> addOperators(string num, int target) {
        tmp+=num[0];
        com=num[0]-'0';
        dfs(num,target,1,com);
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.addOperators("123",6);
  return 0;
}