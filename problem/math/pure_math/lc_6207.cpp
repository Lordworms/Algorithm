/*
容斥来做
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        function<ll(int,int)>get=[&](int ik,int ak)
        {
          ll ans=0,now=0;
          for(auto& k:nums)
          {
              if(k>=ik&&k<=ak)++now;
              else now=0;
              ans+=now;
          }
          return ans;
        };
        return get(minK,maxK)-get(minK+1,maxK)-get(minK,maxK-1)+get(minK+1,maxK-1);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}