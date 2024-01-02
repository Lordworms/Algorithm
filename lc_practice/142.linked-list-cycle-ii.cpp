/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      set<ListNode*> st;
      ListNode *tmp = head;
      while (tmp != nullptr) {
        if (st.count(tmp)) return tmp;
        st.insert(tmp);
        tmp = tmp->next;
      }      
      return nullptr;
    }
};
// @lc code=end

