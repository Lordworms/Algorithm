/*
题意：
    在一条单车道上有 n 辆车，它们朝着同样的方向行驶。给你一个长度为 n 的数组 cars ，其中 cars[i] = [positioni, speedi] ，它表示：
    positioni 是第 i 辆车和道路起点之间的距离（单位：米）。题目保证 positioni < positioni+1 。
    speedi 是第 i 辆车的初始速度（单位：米/秒）。
    简单起见，所有车子可以视为在数轴上移动的点。当两辆车占据同一个位置时，我们称它们相遇了。一旦两辆车相遇，它们会合并成一个车队，这个车队里的车有着同样的位置和相同的速度，速度为这个车队里 最慢 一辆车的速度。
    请你返回一个数组 answer ，其中 answer[i] 是第 i 辆车与下一辆车相遇的时间（单位：秒），如果这辆车不会与下一辆车相遇，则 answer[i] 为 -1 。答案精度误差需在 10-5 以内。

题解：从右往左进行考虑，首先最右侧的值肯定为-1,之后考虑四辆车a b c d如果c能够追上d，那么对于b车来说，有这几种情况
    1.b能追上c，那么也肯定能追上d
    2.b追不上c，但是能追上d     
    前面两种情况，对应的速度都是d的速度（即最慢的速度）
    3.b追不上 c，d ，那么为-1
    对于a也一样，不管能否追上c，d，其答案都是d
    于是我们需要维护一个单调栈，存放递增的速度
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        stack<int>s;
        const double base=1.00000;
        int n=cars.size();
        vector<double>ans(n,-base);
        double up,down,t;
        for(int i=n-1;i>=0;--i)
        {
            while(s.size())
            {
                if(cars[i][1]<=cars[s.top()][1])s.pop();
                else
                {
                    up=cars[s.top()][0]-cars[i][0];
                    down=cars[i][1]-cars[s.top()][1];
                    t=up/down;
                    if(t<ans[s.top()]||ans[s.top()]==-1)break;
                    else s.pop();
                }
            }
            if (s.empty())
            {
                ans[i]=-base;
            }
            else
            {
                ans[i]=t;
            }
            s.push(i);
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<vector<int>>cars={{3,4},{5,4},{6,3},{9,1}};
  sol.getCollisionTimes(cars);
  return 0;
}