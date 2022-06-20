/*
题意：n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
    你需要按照以下要求，给这些孩子分发糖果：
    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。
    请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
题解：两次遍历，我们将题意拆分为两个意思，即对于i和i-1，如果r[i]>r[i-1]则candy[i]=candy[i-1]+1;
    对于右侧同理，最后我们取最大值即可
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy_bad_idea(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>left(n);
        for(int i=0;i<n;++i)
        {
            if(i>0&&ratings[i]>ratings[i-1])
            {
                left[i]=left[i-1]+1;
            }
            else
            {
                left[i]=1;
            }
        }   
        int right=0,ans=0;   
        for(int i=n-1;i>=0;--i)
        {
            if(i!=n-1&&ratings[i]>ratings[i+1])
            {
                ++right;
            }
            else
            {
                right=1;
            }
            ans+=max(left[i],right);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}