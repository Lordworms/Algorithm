/*
01背包裸题，做的时候真的感觉自己可能有点不适合算法，哎，难绷
*/
#include <bits/stdc++.h>
using namespace std;
//直接搞会超时
// class Solution {
// public:
//     int minimizeTheDifference(vector<vector<int>>& mat, int target) {
//         int n=mat.size();
//         vector dp(n,vector<int>(5001));
//         for(int i=0;i<mat[0].size();++i){
//             dp[0][mat[0][i]]=1;
//         }
//         for(int i=1;i<n;++i){
//             for(int v:mat[i]){
//                 for(int k=5000;k>=v;--k){
//                     if(dp[i-1][k-v]){
//                         dp[i][k]=1;
//                     }
//                 }
//             }
//         }
//         int ans=0x3f3f3f3f;
//         for(int i=0;i<5000;++i){
//             if(dp[n-1][i]){
//                 ans=min(ans,abs(i-target));
//             }
//         }
//         return ans;
//     }
// };
//we need to reduce the time 
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        vector dp(n,vector<int>(5001));
        for(int i=0;i<mat[0].size();++i){
            dp[0][mat[0][i]]=1;
        }
        int base=*max_element(mat[0].begin(),mat[0].end());
        for(int i=1;i<n;++i){
            int max_ele=*max_element(mat[i].begin(),mat[i].end());
            for(int v:mat[i]){
                for(int k=base+max_ele;k>=v;--k){
                    dp[i][k]|=dp[i-1][k-v];
                }
            }
            base+=max_ele;
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<5000;++i){
            if(dp[n-1][i]){
                ans=min(ans,abs(i-target));
            }
        }
        return ans;
    }
};
int main(){
  Solution sol;
  vector<vector<int>>mat={{3,5},{4,4},{1,7},{1,1}};
  sol.minimizeTheDifference(mat,67);
  return 0;
}