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
      ListNode *cur = h, *pre = nullptr, *nxt;
      while (cur != nullptr) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
      }
      return pre;
    }
};
// @lc code=end

