/*
题意：给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。
题解：st表+递归
*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    vector<int>nums;
    vector<vector<int>>st;
    vector<int>lg;
    vector<int>bin;
    unordered_map<int,int>mp;
public:
    int query(int l,int r){return max(st[l][lg[r-l+1]],st[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);}
    TreeNode* getTree(int l,int r)
    {
        if(l>r)return nullptr;
        TreeNode* root=new TreeNode;
        int max_num=query(l,r);
        root->val=max_num;
        root->left=getTree(l,mp[max_num]-1);
        root->right=getTree(mp[max_num]+1,r);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        nums=nums;
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]=i;
        }
        auto init_lg=[&](){
            lg.resize(nums.size()+1);
            lg[0]=lg[1]=0;
            for(int i=2;i<=nums.size();++i)lg[i]=lg[i/2]+1;
        };
        auto init_st=[&](){
            vector<vector<int>>st(nums.size(),vector<int>(lg[nums.size()]+1));
            for(int i=0;i<nums.size();++i)st[i][0]=nums[i];
            for(int j=1;j<=lg[nums.size()];++j)
            {
              for(int i=0;i+(1<<j)<=nums.size();++i)
              {
                st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
              }
            }
            return st;
        };
        init_lg(),st=init_st();
        return getTree(0,nums.size()-1);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>arr={3,2,1,6,0,5};
  sol.constructMaximumBinaryTree(arr);
  return 0;
}