/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
      ListNode* pre = nullptr;
      ListNode *cur = head, *nxt;
      while (cur) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
      }
      return pre;
    }
};
// @lc code=end

