#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* create(vector<int>arr)
{
    ListNode* head=new ListNode;
    ListNode* tmp=head;
    for(auto num:arr)
    {
        tmp->val=num;
        tmp->next=new ListNode;
        tmp=tmp->next;
    }
    tmp=nullptr;
    return head;
}
void print(ListNode* head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}
///fuction区域

    struct status
    {
        int val;
        ListNode* ptr;
        bool operator <(const status& now)const
        {
            return val>now.val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode;
        ListNode* tmp=head;
        priority_queue<status>q;
        for(auto node:lists)
        {
            if(node!=nullptr)
            {
                q.push({node->val,node});
            }
        }
        if(q.empty())return nullptr;
        while(!q.empty())
        {
            status now=q.top();
            q.pop();
            tmp->val=now.val;
            if(now.ptr->next!=nullptr)
            {
                q.push({now.ptr->next->val,now.ptr->next});
            }
            if(q.empty())break;
            tmp->next=new ListNode;
            tmp=tmp->next;
        }
        return head;
    }
///
int main()
{
    vector<int>arr={0,2,5};
    ListNode* head=create(arr);
    vector<ListNode*>test;
    test.push_back(head);
    ListNode* res=mergeKLists(test);
    return 0;
}