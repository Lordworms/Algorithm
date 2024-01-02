/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *ans = nullptr, *p = nullptr;
      int add = 0;
      while (l1 || l2) {
        int val = (l1? l1->val : 0) + (l2? l2->val:0) + add;
        add = val >= 10? 1 : 0;
        val %= 10;
        if (!ans) {
          ans = new ListNode(val);
          p = ans;
        } else {
          p->next = new ListNode(val);
          p = p->next;
        }
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }
      if (add) {
        p->next = new ListNode(1);
      }
      return ans;
    }
};
// @lc code=end

