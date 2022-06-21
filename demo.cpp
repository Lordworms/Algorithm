/*
题意：你想要用小写字母组成一个目标字符串 target。 

        开始的时候，序列由 target.length 个 '?' 记号组成。而你有一个小写字母印章 stamp。

        在每个回合，你可以将印章放在序列上，并将序列中的每个字母替换为印章上的相应字母。你最多可以进行 10 * target.length  个回合。

        举个例子，如果初始序列为 "?????"，而你的印章 stamp 是 "abc"，那么在第一回合，你可以得到 "abc??"、"?abc?"、"??abc"。（请注意，印章必须完全包含在序列的边界内才能盖下去。）

        如果可以印出序列，那么返回一个数组，该数组由每个回合中被印下的最左边字母的索引组成。如果不能印出序列，就返回一个空数组。

        例如，如果序列是 "ababc"，印章是 "abc"，那么我们就可以返回与操作 "?????" -> "abc??" -> "ababc" 相对应的答案 [0, 2]；

        另外，如果可以印出序列，那么需要保证可以在 10 * target.length 个回合内完成。任何超过此数字的答案将不被接受
题解：
    逆推法：从target每次通过滑动窗口把对应的部分设置为？，如果碰到？，变为匹配
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m=stamp.size(),n=target.size(),i,j;
        vector<int>ans;
        int count=0,pre=1;
        bool flag=false;
        while(count!=pre)
        {
            pre=count;
            for(int st=0;st<n-m+1;++st){
                i=st,j=0;
                flag=false;
                while(j<m)
                {
                    if(stamp[j]!=target[i]&&target[i]!='?')break;//没法匹配
                    if(target[i]!='?')
                    {
                        flag=true;
                    }
                    ++i,++j;
                }
                if(flag&&j==m)
                {
                    ans.push_back(st);
                    while(--i>=st)
                    {
                        if(target[i]!='?')
                        {
                        ++count;
                        target[i]='?';
                        }
                    }
                }
            }
        }
        if(count!=n){
            return vector<int>();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  string a="abc";
  string b="ababc";
  sol.movesToStamp(a,b);
  return 0;
}