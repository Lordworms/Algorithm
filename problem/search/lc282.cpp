/*
    题面：给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回 所有 能够得到 target 的表达式。
         注意，返回表达式中的操作数 不应该 包含前导零。

    题解：注意这里别直接搜，用for循环搜，便于找到上一个值,一定要好好理解！！！！！！！

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    typedef unsigned long long ll;
    int n;
    vector<string>ans;
    string num;
    int target;
public:
    void dfs(int pos,ll pre,ll cur,string ss)
    {
        if(pos==n)
        {
            if(cur==target)
            ans.push_back(ss);
            return;
        }
        for(int i=pos;i<n;++i)
        {
            if(i!=pos&&num[pos]=='0')break;//去除前导0的聪明方式
            string k=num.substr(pos,i-pos+1);
            long next=stol(k);
            if(pos==0)dfs(i+1,next,cur+next,(string)""+k);
            else
            {
                
                dfs(i+1,next,cur+next,ss+"+"+k);
                dfs(i+1,-next,cur-next,ss+"-"+k);
                ll x=pre*next;
                dfs(i+1,x,cur-pre+x,ss+"*"+k);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        this->n=num.size();
        this->num=num;
        this->target=target;
        dfs(0,0,0,"");
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