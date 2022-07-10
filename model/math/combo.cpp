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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}