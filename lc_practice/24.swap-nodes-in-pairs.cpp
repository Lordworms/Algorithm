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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode *dum = new ListNode(0, head);
      ListNode *tmp = dum;
      while (tmp->next && tmp->next->next) {
        auto l1 = tmp->next;
        auto l2 = tmp->next->next;
        tmp->next = l2;
        l1->next = l2->next;
        l2->next = l1;  
        tmp = l1;
      }    
      return dum->next;
    }
};
// @lc code=end

