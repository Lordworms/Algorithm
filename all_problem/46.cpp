#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void dfs(int pos,vector<int>&nums)
{
    if(pos==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=pos;i<nums.size();++i)
    {
        swap(nums[pos],nums[i]);
        dfs(pos+1,nums);
        swap(nums[i],nums[pos]);
    }

}
vector<vector<int>> permute(vector<int>& nums) 
{
    dfs(0,nums);
    return ans;
}

int main()
{


}