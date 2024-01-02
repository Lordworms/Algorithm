/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
      unordered_set<ListNode*> st;
      ListNode *tmp = head;
      while (tmp != nullptr) {
        if (st.count(tmp)) return true;
        st.insert(tmp);
        tmp = tmp->next;  
      }           
      return false;
    }
};
// @lc code=end

