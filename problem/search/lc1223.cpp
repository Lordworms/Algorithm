/*
题意：
    有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。

不过我们在使用它时有个约束，就是使得投掷骰子时，连续 掷出数字 i 的次数不能超过 rollMax[i]（i 从 1 开始编号）。

现在，给你一个整数数组 rollMax 和一个整数 n，请你来计算掷 n 次骰子可得到的不同点数序列的数量。

假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。由于答案可能很大，所以请返回 模 10^9 + 7 之后的结果。
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>rollMax;
    const int mod=1e9+7;
    int n;
    int dfs(int i,int c,int k)
    {
      if(i==n-1)
      {
        if(c==rollMax[k])return 5;
        return 6;
      }
      int res=0;
      for(int j=0;j<6;++j)
      {
        if(j==k)
        {
          if(c<rollMax[k])res+=dfs(i+1,c+1,k),res%=mod;
        }
        else {res+=dfs(i+1,1,j);res%=mod;}
      }
      return res;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        rollMax=rollMax;
        n=n;
        return dfs(0,0,-1);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>rollMax={1,1,2,2,2,3};
  cout<<sol.dieSimulator(2,rollMax);
  return 0;
}