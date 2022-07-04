/*
题意：给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。

第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j] XOR xi) ，其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。

返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个查询的答案。
题解：建立一棵字典树，然后对元素排序，之后限制一下m的limit即可

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Trie{
        Trie* child[2]={};
        void insert(int x)
        {
            int len=to_string(x).size();
            Trie* node=this;
            for(int i=len-1;i>=0;--i)
            {   
                int bit=(x>>i)&1;
                if(child[bit]==nullptr)
                {
                    child[bit]=new Trie();
                }
                node=node->child[bit];
            }
        }
        int getMaxXor(int x)//获取最大的异或值
        {
            int ans=0;
            int len=to_string(x).size(),bit;
            Trie* node=this;
            for(int i=len-1;i>=0;--i)
            {
                bit=x&(1<<(i));
                if(node->child[bit^1]!=nullptr)//当前位相反的不为空指针
                {
                    ans|=(1<<i);
                    bit^=1;
                }
                else  node=node->child[bit];
            }
            return ans;
        }
    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0;i<queries.size();++i)queries[i].push_back(i);
        int n=nums.size();
        sort(queries.begin(),queries.end(),[&](vector<int>a,vector<int>b){return a[1]<b[1];});
        sort(nums.begin(),nums.end());
        int lim=0;
        Trie* root=new Trie;
        vector<int>ans(queries.size());
        for(int i=0;i<nums.size();++i)
        {
            int id=queries[i][2],m=queries[i][1],x=queries[i][0];
            while(lim<n&&nums[lim]<=m)
            {
                root->insert(nums[lim++]);
            }
            if(lim>0)//动过了
            {
                ans[id]=-1;
            }
            else
            {
                ans[id]=root->getMaxXor(x);
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>nums={0,1,2,3,4};
  vector<vector<int>>que={{3,1},{1,3},{5,6}};
  Solution sol;
  sol.maximizeXor(nums,que);
  return 0;
}