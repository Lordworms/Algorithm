/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Trie {
public:
    static const int N = 3e4 + 10;
    int tr[N][26];
    int count[N * 26];
    int cnt = 0;
    Trie() {
      
    }
    
    void insert(string word) {
      int u = 0;
      for (int i = 0; i < word.size(); ++i) {
        if (!tr[u][word[i] - 'a']) {
          tr[u][word[i] - 'a'] = ++cnt;
        }
        u = tr[u][word[i] - 'a'];
      }
      count[u]++;
    }
    
    bool search(string word) {
      int u = 0;
      for (int i = 0; i < word.size(); ++i) {
        if (!tr[u][word[i] - 'a']) return false;
        u = tr[u][word[i] - 'a'];
      }
      if (count[u]) return true;
      return false;
    }
    
    bool startsWith(string word) {
      int u = 0;
      for (int i = 0; i < word.size(); ++i) {
        if (!tr[u][word[i] - 'a']) return false;
        u = tr[u][word[i] - 'a'];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
int main() {
  Trie a;
  a.insert("apple");
  assert(a.search("apple") == true);
  assert(a.search("app") == false);
  assert(a.startsWith("app") == true);
  a.insert("app");
  assert(a.search("app") == true);
}

