/*
    题面：给出两个整数 n 和 k，找出所有包含从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数。
         逆序对的定义如下：对于数组的第i个和第 j个元素，如果满i < j且 a[i] > a[j]，则其为一个逆序对；否则不是。
    
    题解：定义dp[i][j]为当前使用前i个数字，切正好凑成j个逆序对的情况的数组个数，那么思考对于第i个数字来说，它有i-1个插入位置，设为k
    每个插入位置可以带来i-1-k个逆序对，其中和第i个数不相关的逆序对数量为j-(i-1-k)个，所以容易写出我们的转移方程
        dp[i][j]=求和dp[i-1][j-(i-1-k)]=dp[i-1][j+k+1-i]那么就是我们的答案了
        这里可以做一些优化用


*/
#include <bits/stdc++.h>
using namespace std;
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans=0;
        int now=0,n=brackets.size();
        for(int i=0;i<n;++i)
        {
            if(income>brackets[i][0])
            {
                ans+=(double)(brackets[i][0]-now)*(double)brackets[i][1]/100;
                now=brackets[i][0];
                
            }
            else if(income<brackets[i][0])
            {
                 ans+=(double)(income-now)*(double)brackets[i][1];
                now+=brackets[i][0]-income;
                break;
            }
        }
        return ans;
    }
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>>arr={{1,33}};
  cout<<calculateTax(arr,1);
  return 0;
}