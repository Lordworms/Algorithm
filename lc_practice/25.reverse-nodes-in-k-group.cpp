/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
 public:
  using pii = pair<ListNode *, ListNode *>;
  pii reverse(ListNode *beg, ListNode *end) {
    ListNode *pre = end->next, *cur = beg, *nxt;
    while (pre != end) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;  
    } 
    return {end, beg};
  }
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *pre = new ListNode(0), *tail = pre, *tmp = pre;
    pre->next = head; 
    while (tmp != nullptr) {
      for (int i = 0; i < k; ++i) {
        tail = tail->next;
        if (tail == nullptr) {
          return pre->next;
        }
      }
      auto pi = reverse(head, tail);
      head = pi.first, tail = pi.second;
      tmp->next = head;
      tmp = tail;
      //important!
      head = tail->next;
    }
    return pre->next;
  }
};
// @lc code=end
// int main() {
//   vector<ListNode*> ptrs;
//   int n = 9;
//   for (int i = 1; i <= n; ++i) {
//     ptrs.push_back(new ListNode(i));
//     if (ptrs.size() > 1) ptrs[i - 2]->next = ptrs[i - 1];
//   }
//   Solution sol;
//   sol.reverseKGroup(ptrs[0], 3);
// } 