/*
    本节讲解隔板法，隔板法是怎么做的呢？目前的问题是，有n个盒子，你有k个球，你需要把k个球放入n个盒子中去，那么怎么做呢，n个盒子，对应于n-1个隔板
    那么总共就有n-1+k个位置，我们在这n-1+k个位置中选k个就可以了（或者在n-1+k中选n-1，这里因为k比较小所以选k），这样就把原问题抽象为了一个组合数的问题
    下面是板子

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MAXN=1e4+15;
        const int MK=14;
        const int MOD=1e9+7;
        vector<vector<int>>C(MAXN+1,vector<int>(MK+1,0));//组合数
        vector<int>ks[MAXN];//ks[i]表示i的每个质因子分别有多少个，例如12的话ks[12][0]=2(2个2) ks[12][1]=1(1个3)
        auto init=[&](){
            for(int i=0;i<MAXN;++i)
            {
                for(int j=0;j<=min(i,MK);++j)
                {
                    if(j==0)C[i][j]=1;
                    else C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
                }
            }
            for(int i=2;i<MAXN;++i)
            {
                int x=i;
                for(int p=2;p*p<=x;++p)
                {
                    if(x%p==0)
                    {
                        int k=0;
                        for(;x%p==0;x/=p)++k;
                        ks[i].push_back(k);
                    }
                }
                if(x>1)ks[i].push_back(1);
            }
        };
        init();
        long ans=0;
        for(int i=1;i<=maxValue;++i)
        {
            long mul=1;
            for(int k:ks[i])mul=mul*C[n+k-1][k]%MOD;
            ans=ans+mul%MOD;
        }
        return ans%MOD;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.idealArrays(10000,10000);
  return 0;
}