#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int>mp;
        for(int num:nums)mp[num]++;
        sort(numsDivide.begin(),numsDivide.end());
        int nu=numsDivide[0];
        if(numsDivide.size()>1){
            nu=gcd(numsDivide[0],numsDivide[1]);
            for(int i=2;i<numsDivide.size();++i)nu=__gcd(__gcd(numsDivide[i],numsDivide[0]),nu);
        }
        unordered_set<int>st;
        for(int i=1;i<=nu/2;++i)
        {
            if(nu%i==0)st.insert(i);
        }
        st.insert(nu);
        int ans=0;
        for(auto& it:mp)
        {
            if(st.count(it.first))
            {
                return ans;
            }
            ans+=it.second;
        }
        return -1;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>nums={3,2,6,2,35,5,35,2,5,8,7,3,4};
  vector<int>nums1={105,70,70,175,105,105,105};
  Solution sol;
  sol.minOperations(nums,nums1);
  return 0;
}