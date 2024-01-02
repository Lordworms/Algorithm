/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
 private:
   ListNode *left;
 public:
  bool recursive(ListNode* cur) {
    if (cur != nullptr) {
      if (!recursive(cur->next)) {
        return false;
      }
      if (cur->val != left->val) {
        return false;
      }
      left = left->next;
    }
    return true;
  }
  bool isPalindrome(ListNode* head) {
    left = head;
    return recursive(head);
  }
};
// @lc code=end
