/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<bool>isValid(m*n+1,true);
        for(auto& a:broken)isValid[a[0]*m+a[1]]=false;
        int maxMask=pow(3,m),midMask=pow(3,m-1),minMask=pow(3,max(m-2,0));
        vector<vector<int>>dp(n*m+1,vector<int>(maxMask,0));
        int left,up;
        for(int id=m*n-1;id>=0;--id)
        {
            int i=id/m,j=id%m;
            for(int mask=0;mask<maxMask;++mask)
            {
                int now=(mask*3)%maxMask;
                dp[id][mask]=max(dp[id][mask],dp[id+1][now]);
                if(!isValid[id])continue;
                if(j>0&&isValid[id-1]&&(mask%3)==0)//放左边,保证前一位是0
                {
                    dp[id][mask]=max(dp[id][mask],dp[id+1][now+1]+1);
                }
                if(i>0&&isValid[id-m])//不在第一行，上面可以放
                {
                    if(mask/midMask||((mask/minMask)%3)==1)continue;
                    dp[id][mask]=max(dp[id][mask],dp[id+1][now+2]+1);
                }
                
            }
            
        }
        return dp[0][0];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;

  return 0;
}