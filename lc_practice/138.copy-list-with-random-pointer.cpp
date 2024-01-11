/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

class Solution {
 private:
  map<Node*, Node*> mp;

 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return head;
    if (mp.find(head) == mp.end()) {
      mp[head] = new Node(head->val);
      mp[head]->next = copyRandomList(head->next);
      mp[head]->random = copyRandomList(head->random);
    }
    return mp[head];
  }
};
// @lc code=end