/*
给你一个下标从 0 开始的二维整数数组 transactions，其中transactions[i] = [costi, cashbacki] 。

数组描述了若干笔交易。其中每笔交易必须以 某种顺序 恰好完成一次。在任意一个时刻，你有一定数目的钱 money ，为了完成交易 i ，money >= costi 这个条件必须为真。执行交易后，你的钱数 money 变成 money - costi + cashbacki 。

请你返回 任意一种 交易顺序下，你都能完成所有交易的最少钱数 money 是多少。
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& trans) {
        using ll=long long;
        ll ans=0;
        ll minus=0;
        for(auto s:trans)
        {
            ll minu=s[1]-s[0];
            if(minu<0)minus+=minu;
        }
        for(auto s:trans)
        {
            ll det=s[1]-s[0];
            if(det<0)
            {
                ans=max(ans,s[0]-(minus-det));
            }
            else
            {
                ans=max(ans,s[0]-minus);
            }
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