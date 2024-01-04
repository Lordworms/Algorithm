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
    ListNode *dum = new ListNode(0, head), *tail = dum, *pre = dum;
    while (tail != nullptr) {
      for (int i = 0; i < k; ++i) {
        tail = tail->next;
        if (tail == nullptr) return dum->next;
      }
      ListNode *nxt = tail->next;
      auto pi = reverse(head, tail);
      head = pi.first;
      tail = pi.second;
      pre->next = head;
      tail->next = nxt;
      pre = tail;
      head = tail->next;
    }
    return dum->next;
  }
};
// @lc code=end
