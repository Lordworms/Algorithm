#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
TreeNode* build(vector<int>& nums,int l,int r)
{
        if(l>r)return nullptr;
        int mid=(l+r)>>1;
        TreeNode* tmp=new TreeNode(nums[mid]);
        tmp->left=build(nums,l,mid-1);
        tmp->right=build(nums,mid+1,r);
        return tmp;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n=nums.size();
    return build(nums,0,n-1);  
}
int main()
{
    vector<int>nums={-10,-3,0,5,9};
    TreeNode* root=sortedArrayToBST(nums);
    return 0;
}