/*
题意：给你一个整数数组 nums （下标 从 0 开始 计数）以及两个整数：low 和 high ，请返回 漂亮数对 的数目。

漂亮数对 是一个形如 (i, j) 的数对，其中 0 <= i < j < nums.length 且 low <= (nums[i] XOR nums[j]) <= high 
题解：直接暴力会超时的，所以我们考虑用字典树来存对应的值，每次当有新的值前来的时候，我们先判定有多少数比异或后小于high，令这个函数为check。那么
对应的解为check(high+1)-check(low)，加上去就可以了
    num^x=target 其中x为树中的数字，那么对于target和num的每一位来说我们分类讨论
    target    num       x
     1          0       加上为0的部分
     1          1       加上为1的部分
     0          0       继续向下递归0，不然就比0大了
     0          1       继续向下递归1,不然就比0大了
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Trie{
       int size=0;
       const int len=16;
       Trie* ch[2];
       void init()
       {
            this->ch[0]=nullptr,this->ch[1]=nullptr;
       }
       void insert(int num) 
       {
            Trie* node=this;
            for(int i=len-1;i>=0;--i)
            {
                int bit=(num>>i)&1;
                if(node->ch[bit]==nullptr)//重点！！！！
                {
                    node->ch[bit]=new Trie();
                    node->ch[bit]->init();
                }
                node=node->ch[bit];
                node->size++;
            }
       }
       int find(int num,int lim)
       {
            Trie* node=this;
            int ans=0;
            for(int i=len-1;i>=0;--i)
            {
                int bit_num=(num>>i)&1;
                int bit_lim=(lim>>i)&1;
                if(node==nullptr)return ans;//重点，直接返回
                if(bit_lim)
                {
                    if(node->ch[bit_num]!=nullptr)
                    {
                        ans+=node->ch[bit_num]->size;
                    }
                    bit_num^=1;
                }
                node=node->ch[bit_num];
            }
            return ans;
       }
    };
    int countPairs(vector<int>& nums, int low, int high) {
        Trie* node=new Trie();
        node->init();
        int ans=0;
        for(int num:nums)
        {
            ans+=node->find(num,high+1)-node->find(num,low);
            node->insert(num);
        } 
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>nums={1,4,2,7};
  Solution sol;
  cout<<sol.countPairs(nums,2,6);
  return 0;
}