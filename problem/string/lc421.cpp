/*
题意：给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
题解：01字典树板子题
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Trie{
        int len=32;
        Trie* ch[2];
        void init(){this->ch[0]=this->ch[1]=nullptr;}
        void insert(int num)
        {
            Trie* node=this;
            for(int i=len-1;i>=0;--i)
            {
                int bit=(num>>i)&1;
                if(node->ch[bit]==nullptr)
                {
                    node->ch[bit]=new Trie();
                    node->ch[bit]->init();
                }   
                node=node->ch[bit];
            }
        }
        int findMax(int num)
        {
            Trie* node=this;
            int ans=0;
            for(int i=len-1;i>=0;--i)
            {
                if(node==nullptr)return ans;
                int bit=(num>>i)&1;
                if(node->ch[bit^1]!=nullptr)
                {
                    ans|=(1<<i);
                    bit^=1;
                }
                node=node->ch[bit];
            }
            return ans;    
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        Trie* node=new Trie();node->init();
        for(int num:nums)
        {
            ans=max(ans,node->findMax(num));
            node->insert(num);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>nums={14,70,53,83,49,91,36,80,92,51,66,70};
  cout<<sol.findMaximumXOR(nums);
  return 0;
}