/*
    题意：给你一个整数数组 nums ，请你返回所有下标对 0 <= i, j < nums.length 的 floor(nums[i] / nums[j]) 结果之和。由于答案可能会很大，请你返回答案对109 + 7 取余 的结果。
        函数 floor() 返回输入数字的整数部分。

    题解：
        前缀和来做
        容易想到枚举x和y来进行操作，但是会超时，我们此时枚举y和d=[x/y]
        那么此时满足要求的x在[d*y,(d+1)*y)区间内,所以我们的答案为
        num(x)*num(y)*d的求和

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MOD=1e9+7;
    using ll=long long;
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n=nums.size(),maxn=*max_element(nums.begin(),nums.end());
        vector<int>h(maxn+1,0);
        vector<int>cnt(maxn+1,0);
        for(int&num:nums)cnt[num]++;
        for(int i=1;i<=maxn;++i)h[i]=h[i-1]+cnt[i];//前缀和
        ll ans=0;
        for(int y=1;y<=maxn;++y)
        {
            if(cnt[y])
            {
                for(int d=1;d*y<=maxn;++d)
                {
                    ans=(ans+cnt[y]*(h[min((d+1)*y-1,maxn)]-h[d*y-1])*d)%MOD;//注意右边开区间，所以-1
                }
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>nums={2,5,9};
  cout<<sol.sumOfFlooredPairs(nums);
  return 0;
}