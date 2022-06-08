#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void show(ListNode* root)
{
    ListNode* tmp=root;
    while(tmp!=nullptr)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
ListNode* create(int arr[],int length)
{
    ListNode* root=new ListNode;
    ListNode* tmp=root;
    for(int i=0;i<length;++i)
    {
        tmp->val=arr[i];
        if(i!=length-1)
        {
            tmp->next=new ListNode;
            tmp=tmp->next;
        }
    }
    return root;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans=new ListNode;
    ListNode* tmp=ans;
    int carry=0;
    while(1)
    {
        
        tmp->val=((l1==nullptr?0:l1->val)+(l2==nullptr?0:l2->val)+carry)%10;
        carry=((l1==nullptr?0:l1->val)+(l2==nullptr?0:l2->val)+carry)/10;
        l1=l1==nullptr?nullptr:l1->next;
        l2=l2==nullptr?nullptr:l2->next;
        if(l1==nullptr&&l2==nullptr)//最后一位了
        {
            if(carry>0)
            {
               tmp->next=new ListNode;
               tmp=tmp->next;
               tmp->val=1;
              
            }
             break; 
        }
        tmp->next=new ListNode;
        tmp=tmp->next;
    }
    return ans;
}
int main()
{
    //int a[]={9,9,9,9,9,9,9};
    //int b[]={9,9,9,9};
    int a[]={2,4,3};
    int b[]={5,6,4};
    ListNode* l1=create(a,3);
    ListNode* l2=create(b,3);
    ListNode* res=addTwoNumbers(l1,l2);
    show(res);


}