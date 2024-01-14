/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] Sort List
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
 public:
  ListNode *sortList(ListNode *head) { 
    return merge_sort(head, nullptr); 
  }
  ListNode *merge_sort(ListNode *left, ListNode *right) {
    if (left == nullptr) {
      return nullptr;
    }
    if (left->next == right) {
      //most important
      left->next = nullptr;
      return left;
    }
    ListNode *slow = left, *fast = left;
    while (fast != right) {
      slow = slow->next;
      fast = fast->next;
      if (fast != right) {
        fast = fast->next;
      }
    }
    ListNode *mid = slow;
    return merge(merge_sort(left, mid), merge_sort(mid, right));
  }
  ListNode* merge(ListNode *left, ListNode *right) {
    ListNode *dum = new ListNode(0), *tmp = dum, *l = left, *r = right;
    while (l != nullptr && r != nullptr) {
      if (l->val < r->val) {
        tmp->next = l;
        l = l->next;
      } else {
        tmp->next = r;
        r = r->next;
      }
      tmp = tmp->next;
    }
    if (l != nullptr) {
      tmp->next = l;
    }
    if (r != nullptr) {
      tmp->next = r;
    }
    return dum->next;
  }
};
// @lc code=end
// int main() {
//   vector<int> a = {4, 2, 1, 3};
//   vector<ListNode *> v(a.size());
//   for (int i = 0; i < a.size(); ++i) {
//     v[i] = new ListNode(a[i]);
//     if (i) {
//       v[i - 1]->next = v[i];
//     }
//   }
//   Solution sol;
//   auto k = sol.sortList(v[0]);
//   return 0;
// }
