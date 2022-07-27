/*
    组合数递推公式：cab=ca(b-1)+c(a-1)(b-1)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=2010;
const int mod=1e9+7;
void init()
{
    vector<vector<int>>C(N,vector<int>(N,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0) C[i][j]=1;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int get_inv(int n)//递归方式求
{
  return n==1?1:get_inv(mod%n)*(mod-mod/n);
}
int C(int n,int m)
{
    if(m<0||m>n)return 0;
    int up=1,down=1;
    for(int i=0;i<m;++i)
    {
        up=up*(n-i)%mod;
        down=down*(i+1)%mod;
    }
    return up*get_inv(down);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}