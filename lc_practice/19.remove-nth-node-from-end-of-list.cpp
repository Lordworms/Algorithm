/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *dum = new ListNode(0, head);
      ListNode *l1 = head;
      ListNode *l2 = dum;
      for (int i = 0; i < n; ++i) {
        l1 = l1->next;
      }      
      while (l1) {
        l1 = l1->next;
        l2 = l2->next;
      }
      l2->next = l2->next->next;
      return dum->next;
    }
};
// @lc code=end

