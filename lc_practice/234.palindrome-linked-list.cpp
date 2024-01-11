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
 private:
  ListNode *left;

 public:
  bool is_pad(ListNode *cur) {
    bool ans = true;
    if (cur->next != nullptr) {
      ans &= is_pad(cur->next);
    }
    if (cur->val == left->val) {
      ans &= true;
    } else {
      ans &= false;
    }
    left = left->next;
    return ans;
  }
  bool isPalindrome(ListNode *head) {
    left = head;
    return is_pad(head);
  }
};
// @lc code=end
