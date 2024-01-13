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
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
 public:
  ListNode *sortList(ListNode *head) { return merge_sort(head, nullptr); }
  ListNode *merge(ListNode *l, ListNode *r) {
    ListNode *dum = new ListNode(0), *cur = dum, *L = l, *R = r;
    while (L != nullptr && R != nullptr) {
      if (L->val < R->val) {
        cur->next = L;
        L = L->next;
      } else {
        cur->next = R;
        R = R->next;
      }
      cur = cur->next;
    }
    if (L != nullptr) {
      cur->next = L;
    } else if (R != nullptr) {
      cur->next = R;
    }
    return dum->next;
  }
  ListNode *merge_sort(ListNode *head, ListNode *tail) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == tail) {
      head->next = nullptr;
      return head;
    }
    ListNode *slow = head, *fast = head;
    while (fast != tail) {
      fast = fast->next;
      slow = slow->next;
      if (fast != tail) {
        fast = fast->next;
      }
    }
    ListNode *mid = slow;
    return merge(merge_sort(head, mid), merge_sort(mid, tail));
  }
};
// @lc code=end
int main() {
  vector<int> a = {4, 2, 1, 3};
  vector<ListNode *> v(a.size());
  for (int i = 0; i < a.size(); ++i) {
    v[i] = new ListNode(a[i]);
    if (i) {
      v[i - 1]->next = v[i];
    }
  }
  Solution sol;
  sol.sortList(v[0]);
}
