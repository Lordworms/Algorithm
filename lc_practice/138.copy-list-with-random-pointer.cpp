/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start

// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };


class Solution {
private:
    map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
      if (head == nullptr) {
        return nullptr;
      }       
      if (mp.find(head) == mp.end()) {
       Node *head_new = new Node(head->val);
       mp[head] = head_new;
       head_new->next = copyRandomList(head->next);
       head_new->random = copyRandomList(head->random);
      }
      return mp[head];
    }
};
// @lc code=end

