/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
class Solution {
 public:
ListNode* mergeTwoLists(ListNode* L1, ListNode* L2) {
    ListNode *ans = new ListNode(), *tmp = ans, *l1 = L1, *l2 = L2;
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    while (l1 != nullptr || l2 != nullptr) {
      if (l2 == nullptr) {
        tmp->val = l1->val;
        l1 = l1->next;
      } else if (l1 == nullptr) {
        tmp->val = l2->val;
        l2 = l2->next;
      } else if (l1->val < l2->val) {
        tmp->val = l1->val;
        l1 = l1->next;
      } else {
        tmp->val = l2->val;
        l2 = l2->next;
      }
      if (l1 != nullptr || l2 != nullptr) {
        tmp->next = new ListNode();
        tmp = tmp->next;
      }
    }
    return ans;
  }
};
// @lc code=end
