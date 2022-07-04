/*
题意：给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
题解：采用字典树的思想，我们对树进行先序遍历，对于每一次，我们分别计算每一层对应的节点数，如果不满足当前节点，那么我们就向下走，否则就向右走
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    ll getCount(int cur,int lim)
    {
        ll count=0,first=cur,last=cur;
        while(first<=lim)
        {
            count+=min(last,(ll)lim)-first+1;
            first*=10;
            last=last*10+9;
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        int ans=1;
        --k;
        while(k)
        {
            ll count=getCount(ans,n);
            if(count<=k)//向右走
            {
                k-=count;
                ans++;
            }
            else
            {
                ans*=10;
                k-=1;
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.findKthNumber(13,2);
return 0;
}