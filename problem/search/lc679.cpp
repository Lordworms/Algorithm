/*
    题面：给定一个长度为4的整数数组 cards 。你有 4 张卡片，每张卡片上都包含一个范围在 [1,9] 的数字。您应该使用运算符
     ['+', '-', '*', '/'] 和括号 '(' 和 ')' 将这些卡片上的数字排列成数学表达式，以获得值24。
    你须遵守以下规则:
            除法运算符 '/' 表示实数除法，而不是整数除法。
            例如， 4 /(1 - 2 / 3)= 4 /(1 / 3)= 12 。
            每个运算都在两个数字之间。特别是，不能使用 “-” 作为一元运算符。
            例如，如果 cards =[1,1,1,1] ，则表达式 “-1 -1 -1 -1” 是 不允许 的。
            你不能把数字串在一起
            例如，如果 cards =[1,2,1,2] ，则表达式 “12 + 12” 无效。
            如果可以得到这样的表达式，其计算结果为 24 ，则返回 true ，否则返回 false 。
    题解：
        明显是一道搜索题，我们熟悉,然后照着题意搜索就行了，记得在本题的范围内，我们认为小于1e-6即可认为是0，在进行计算的时候需要注意
        然后再就是重复的问题，如果k<2&&i>j的话我们不需要重复计算加减，因为已经被计算了一次了，注意i和j都要从0开始遍历，这是因为我们需要i/j和j/i
        先sort一下，免得出错
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int ADD=0;
    const int SUB=1;
    const int MUL=2;
    const int DIV=3;
    const double TARGET=24;   
    const double EPSILON=1e-6;
public:
    bool dfs(vector<double>& now)
    {
        int n=now.size();
        if(n==0)
        {
            return false;
        }
        if(n==1)
        {
            if(fabs(TARGET-now[0])<EPSILON)
            {
                return true;
            }
        }
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j)continue;
                vector<double>tmp;
                for(int k=0;k<n;++k)
                {
                    if(k!=i&&k!=j)
                    {
                        tmp.push_back(now[k]);
                    }
                }
                for(int k=0;k<4;++k)
                {
                    if(k<2&&i>j)continue;
                    if(k==ADD)
                    {
                        tmp.push_back(now[i]+now[j]);
                    }
                    else if(k==SUB)
                    {
                        tmp.push_back(now[i]-now[j]);
                    }
                    else if(k==DIV)
                    {
                        if(fabs(now[j])<EPSILON)continue;
                        tmp.push_back(now[i]/now[j]);
                    }
                    else if(k==MUL)
                    {
                        tmp.push_back(now[i]*now[j]);
                    }
                    if(dfs(tmp))
                    {
                        return true;
                    }
                    tmp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double>now;
        for(auto& num:cards)now.push_back(static_cast<double>(num));
        return dfs(now);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>card={7,4,9,1};
  sol.judgePoint24(card);
  return 0;
}