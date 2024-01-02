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
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* h) {
      if (h == nullptr) return nullptr;
      ListNode *cur = h, *pre = nullptr, *nxt = cur->next;
      while (cur != nullptr && nxt != nullptr) {
        cur->next = pre;
        pre = cur;
        cur = nxt;
        nxt = nxt->next;
      }
      cur->next = pre;
      return cur;
    }
};
// @lc code=end

