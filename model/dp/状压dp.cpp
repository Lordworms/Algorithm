#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        numSlots*=2;
        vector<int>f(1<<numSlots);//定义f为当放了nums中的前c个元素时候的最大值，其中i的二进制中含有的1的个数
        for(int i=0;i<f.size();++i)
        {
            int c=__builtin_popcount(i);
            if(c>=nums.size())continue;
            for(int j=0;j<numSlots;++j)
            {
                if((i&(1<<j))==0)//这个j是空的篮子
                {
                    int k=i|(1<<j);
                    f[k]=max(f[k],f[i]+(nums[c]&(j/2+1)));
                }
            }
        }
        return *max_element(f.begin(),f.end());
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}