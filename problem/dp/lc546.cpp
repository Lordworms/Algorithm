/*
    题面：给出一些不同颜色的盒子 boxes ，盒子的颜色由不同的正数表示。

你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k * k 个积分。

返回 你能获得的最大积分和 。

    题解：容易看出这是个区间dp问题，那么我们就很容易用dp[i][j]表示区间[i,j]内可以获得的最大积分，但是区间内可以获得的最大积分并不只依赖于子序列，
    还依赖于我们对于其移动的这个位置（因为要合并），所以我们得用第三维来表示这个值的影响
    {6,3,6,5,6,7,6,6,8,6}
    对于我们的这个序列，我们用dp[i][j][k]表示删除i-j区间和之后与a[j]相等的k个元素能够获得的最大值
    那么对于我们{6,3,6,5,6}这个区间来说，我们可以做如下两种策略：
    1.先移除最后的4个6，然后再管前面的dp[i][j][k]=dp[i][j-1]+(k+1)^2
    2.找到区间内和j位置相等的值,设为q，先移除右半部分，再移除左半部分。然后dp[i][j][k]=max(dp[i][j][k],dp[i][q][k+1]+dp[q+1][j-1][0])

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int MAXN=101;
    int dp[MAXN][MAXN][MAXN];
    vector<int>boxes;
public:
    int getAns(int l,int r,int k)
    {   
        if(l>r)return 0;
        if(dp[l][r][k]==0)
        {
            dp[l][r][k]=getAns(l,r-1,0)+(k+1)*(k+1);
        
            for(int i=l;i<r;++i)
            {
                if(boxes[r]==boxes[i])
                {
                    dp[l][r][k]=max(dp[l][r][k],getAns(l,i,k+1)+getAns(i+1,r-1,0));
                }
            }
        }
        return dp[l][r][k];
    }
    int removeBoxes(vector<int>& boxes) {
        this->boxes=boxes;
        memset(dp,0,sizeof(dp));
        return getAns(0,boxes.size()-1,0);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>boxes={1,3,2,2,2,3,4,3,1};
  int x=sol.removeBoxes(boxes);
  return 0;
}