#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target)return 0;
            return -1;
        }
        int l=0,r=nums.size()-1,m;
        while(l<r)
        {   
            m=(l+r)>>1;
            if(nums[m]==target)return m;
            if(nums[l]==target)return l;
            if(nums[r]==target)return r;
            if(nums[m]>nums[l])//左边有序
            {
                if(nums[m]>target&&nums[l]<=target)
                {
                    r=m-1;
                }
                else
                {
                    l=m+1;
                }
            }
            else
            {
                if(nums[m]<target&&nums[r]>=target)
                {
                    l=m+1;
                }
                else
                {
                    r=m-1;
                }
            }
        }
        return -1;
}
int main()
{
    vector<int>nums={4,5,6,7,0,1,2};
    cout<<search(nums,5);
}