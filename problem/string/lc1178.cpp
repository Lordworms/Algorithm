/*
题意：
    外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。

    字谜的迷面 puzzle 按字符串形式给出，如果一个单词 word 符合下面两个条件，那么它就可以算作谜底：

    单词 word 中包含谜面 puzzle 的第一个字母。
    单词 word 中的每一个字母都可以在谜面 puzzle 中找到。
    例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）都不能作为谜底。
    返回一个答案数组 answer，数组中的每个元素 answer[i] 是在给出的单词列表 words 中可以作为字谜迷面 puzzles[i] 所对应的谜底的单词数目。


题解：枚举子状态就完事了，注意二进制的运用，另一种方式是使用字典树
    枚举状态的时候记得全0的状态也要枚举进去，所以这个时候需要我们设置一个flag表示可以枚举一次0的情况

*/
#include <bits/stdc++.h>
using namespace std;
class Trie {
public:
    const int L = 30;

    Trie* children[2] = {};

    void insert(int val) {
        Trie* node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int val) {
        int ans = 0;
        Trie* node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr) {
                ans |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        sort(nums.begin(), nums.end());
        int numQ = queries.size();
        for (int i = 0; i < numQ; ++i) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](auto &x, auto &y) { return x[1] < y[1]; });

        vector<int> ans(numQ);
        Trie* t = new Trie();
        int idx = 0, n = nums.size();
        for (auto &q : queries) {
            int x = q[0], m = q[1], qid = q[2];
            while (idx < n && nums[idx] <= m) {
                t->insert(nums[idx]);
                ++idx;
            }
            if (idx == 0) { // 字典树为空
                ans[qid] = -1;
            } else {
                ans[qid] = t->getMaxXor(x);
            }
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