#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int k;
        vector<int>ans;
        struct node{int id;string s;};
        vector<node>arr;
        for(int i=0;i<nums.size();++i)arr.push_back({i,nums[i]});
        int n=nums[0].size();
        for(auto q:queries)
        {
            k=q[1];
            sort(arr.begin(),arr.end(),[&](node a,node b){
                if(k>=n)return a.s<b.s;
                for(int i=n-k;i<n;++i)
                {
                    if(a.s[i]!=b.s[i])return a.s[i]<b.s[i];
                }
                return a.id<b.id;
            });    
            ans.push_back(arr[q[0]-1].id);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<string>nums={"102","473","251","814"};
  vector<vector<int>>query={{1,1},{2,3},{4,2},{1,2}};
  sol.smallestTrimmedNumbers(nums,query);
  return 0;
}