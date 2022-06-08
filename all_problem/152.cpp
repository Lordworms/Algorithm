#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int>& nums) {
        int l=0,r=0;
        int max_pro=-0xff;
        int now_pro=1;
        int n=nums.size();
        while(r<n)
        {
           while(r<n&&nums[r]*now_pro<max_pro)
           {
               now_pro*=nums[r];
               
           }
        }
        return max_pro;
}
int main()
{
    vector<int>nums={0,2};
    cout<<maxProduct(nums)<<endl;
}