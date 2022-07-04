/*
题意：
    外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

    字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

    单词 word 中包含谜面 puzzle 的第一个字母。
    单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
    例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）都不能作为谜底。
    返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。


题解：枚举子状态就完事了，注意二进制的运用，另一种方式是使用字典树
    枚举状态的时候记得全0的状态也要枚举进去，所以这个时候需要我们把

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int>freq;
        vector<bitset<26>>bvec;
        for(string& word:words)
        {
            int mask=0;
            for(char& c:word)
            {
                mask|=(1<<(c-'a'));
            }
            int n=__builtin_popcount(mask);
            if(n<=7)
            {
                ++freq[mask];   
            }
            bvec.push_back(bitset<26>(mask));
        }
        vector<int>ans;
        for(string puz:puzzles)
        {
            int mask=0,total=0;
            for(int i=1;i<puz.size();++i)mask|=(1<<(puz[i]-'a'));
            for(int sub=mask,flag=true;flag;sub=((sub-1)&mask))
            {
                int s=(sub|(1<<(puz[0]-'a')));
                if(sub==0)flag=false;
                bitset<26>a(s);
                if(freq.count(s))
                {
                    total+=freq[s];
                }
            }
            ans.push_back(total);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<string>words={"aaaa","asas","able","ability","actt","actor","access"};
  vector<string>puz={"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
  sol.findNumOfValidWords(words,puz);
  return 0;
}