/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    struct Node {
      ListNode *ptr;
      int val;
      bool operator < (const Node &a) const{
        return val > a.val;
      }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<Node> q;
      for (auto a : lists) {
        if (a != nullptr) q.push({a, a->val});
      }
      ListNode *dum = new ListNode();
      ListNode *tmp = dum;
      while (!q.empty()) {
        auto p = q.top();
        q.pop();
        tmp->next = p.ptr;
        if (p.ptr->next != nullptr) {
          q.push({p.ptr->next, p.ptr->next->val});
        }
        tmp = tmp->next;
      }      
      return dum->next;
    }
};
// @lc code=end

