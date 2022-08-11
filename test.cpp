/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
		vector<pair<int,int>>t;
		for(int i=0;i<nums2.size();++i)t.push_back((pair<int,int>){nums2[i],i});
		sort(t.begin(),t.end());
		vector<int>ans(nums1.size());
		int l=0,r=nums1.size()-1,cnt=nums2.size()-1;
		while(cnt>=0)
		{
			if(nums1[r]>t[cnt].first)
			{
				ans[t[cnt].second]=nums1[r];
				--r;
			}
			else
			{
				ans[t[cnt].second]=nums1[l];
				++l;
			}
			--cnt;
		}
		return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>arr1={12,24,8,32},arr2={13,25,32,11};
  Solution sol;
  sol.advantageCount(arr1,arr2);
  return 0;
}