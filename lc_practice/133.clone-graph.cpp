/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
class Solution {
private:
    map<Node*, Node*> mp;
    map<Node*, int> cnt;
    map<Node*, set<Node*>> st;
public:
    Node* cloneGraph(Node* node) {
      if (node == nullptr) return nullptr;
      cnt[node]++;
      if (mp.find(node) == mp.end()) {
        mp[node] = new Node(node->val);
      } else {
        return mp[node];
      }
      for (auto &v : node->neighbors) {
        if (!st[node].count(v)) {
          mp[node]->neighbors.push_back(cloneGraph(v));
          st[node].insert(v);
        }
      }   
      return mp[node];
    }
};
// @lc code=end
// int main() {
//   Solution sol;
//   int n = 4;
//   vector<Node*> a(n + 1);
//   for (int i = 1; i <= n; ++i) {
//     a[i] = new Node(i);
//   }
//   a[1]->neighbors.push_back(a[2]);
//   a[1]->neighbors.push_back(a[4]);
//   a[2]->neighbors.push_back(a[4]);
//   a[2]->neighbors.push_back(a[1]);
//   a[3]->neighbors.push_back(a[2]);
//   a[3]->neighbors.push_back(a[4]);
//   a[4]->neighbors.push_back(a[1]);
//   a[4]->neighbors.push_back(a[3]);
//   auto ans = sol.cloneGraph(a[1]);
//   return 0;
// }

