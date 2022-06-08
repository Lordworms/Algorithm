#include<bits/stdc++.h>
using namespace std;
vector<int>arr={};
vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    for(int first=0;first<n;++first)
    {
        int third=n-1;
        if(first!=0&&nums[first]==nums[first-1])continue;
        for(int second=first+1;second<n;++second)
        {
            if(second!=first+1&&nums[second]==nums[second-1])
            {
                continue;
            }
            while(third>second&&nums[second]+nums[third]>(-nums[first]))
            {
                third--;
            }
            if(third==second)break;
            if(nums[second]+nums[third]==(-nums[first]))
            {
                ans.push_back({nums[first],nums[second],nums[third]});
            }
        }
    }
    return ans;    
}
int main()
{

}