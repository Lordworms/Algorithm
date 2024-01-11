/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    ListNode *dum = new ListNode(0, head);
    ListNode *pre = dum, *cur = head, *nxt, *nnxt;
    while (pre->next && pre->next->next) {
      auto l1 = pre->next, l2 = pre->next->next;
      pre->next = l2;
      l1->next = l2->next;
      l2->next = l1;
      pre = l1;  
    }
    return dum->next;
  }
};
// @lc code=end
// int main() {
//   ListNode *a4 = new ListNode(4);
//   ListNode *a3 = new ListNode(3, a4);
//   ListNode *a2 = new ListNode(2, a3);
//   ListNode *a1 = new ListNode(1, a2);
//   Solution sol;
//   sol.swapPairs(a1);
// }
