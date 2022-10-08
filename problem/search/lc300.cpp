#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        int l,r,m;
        for(auto num:nums)
        {
            l=-1,r=dp.size();
            while(l+1!=r)
            {
                m=(l+r)>>1;
                if(dp[m]<num)
                {
                    l=m;
                }
                else r=m;
            }
            if(r==dp.size())
            {
                dp.push_back(num);
            }
            else
            {
                dp[r]=num;
            }
        }
        return dp.size();
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}