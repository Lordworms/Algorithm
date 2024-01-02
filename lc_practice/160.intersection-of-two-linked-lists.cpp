/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
#include <bits/stdc++.h>
using namespace std;
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
      //  a b c, when they are equal all  traverse through a + b + c
      if (a == nullptr || b == nullptr) return nullptr;
      ListNode *pa = a, *pb = b;
      while (pa != pb) {
        pa = pa == nullptr? b : pa->next;
        pb = pb == nullptr? a : pb->next;
      }    
      return pa;
    }
};
// @lc code=end

