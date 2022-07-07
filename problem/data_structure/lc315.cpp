/*
题意：给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： 
counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
题解：离线离散化树状数组板子题
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>tree(n+1,0);
        auto lowbit=[&](int x){return x&-x;};
        auto add=[&](int x,int v){while(x<=n){tree[x]+=v,x+=lowbit(x);}};
        auto sum=[&](int x){int ans=0;while(x){ans+=tree[x],x-=lowbit(x);};return ans;}; 
        auto getDiscrete=[&](vector<int>& arr){
            vector<int>b(arr);
            sort(b.begin(),b.end());
            b.erase(unique(b.begin(),b.end()),b.end());
            for(int i=0;i<arr.size();++i)arr[i]=lower_bound(b.begin(),b.end(),arr[i])-b.begin()+1;
        };
        getDiscrete(nums);
        vector<int>ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;--i)
        {
            ans[i]=sum(nums[i]-1);//注意树状数组求的是[0,nums[i]]是开区间
            add(nums[i],1);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>arr={-1,-1};
  sol.countSmaller(arr);
  return 0;
}