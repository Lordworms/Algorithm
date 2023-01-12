#include <bits/stdc++.h>
using namespace std;
void calc(vector<vector<int>>a)
{
    int n=a.size(),m=a[0].size();
    vector sum(n+1,vector<int>(m));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i-1][j-1];
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}