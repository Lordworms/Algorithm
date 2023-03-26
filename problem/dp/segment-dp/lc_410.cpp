#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    int splitArray(vector<int>& nums, int m) {
        ll LIM=1e9;
        int n=nums.size();
        vector<ll>sum(n+1);
        for(int i=1;i<=n;++i){
            sum[i]=sum[i-1]+nums[i-1];
        }
        vector dp(n+1,vector<ll>(m+1,LIM));
        dp[0][0]=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=min(m,i);++j){
                for(int k=0;k<i;++k){
                    dp[i][j]=min(dp[i][j],max(dp[k][j-1],sum[i]-sum[k]));
                }
            }
        }
        return dp[n][m];
    }
};
int main(){
  vector<int>a={7,2,5,10,8};
  Solution sol;
  sol.splitArray(a,2);
  return 0;
}