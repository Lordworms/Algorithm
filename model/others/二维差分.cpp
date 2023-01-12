#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int dif[N][N];
void calc(vector<vector<int>>a)
{
    int n=a.size(),m=a[0].size();
    memset(dif,0,sizeof(dif));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dif[i][j]=a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
        }
    }
}
void recover(vector<vector<int>>&dif)
{
    int n=dif.size()-1,m=dif[0].size()-1;
    vector a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]=dif[i][j]-a[i-1][j-1]+a[i-1][j]+a[i][j-1];
        }
    }
}
void modify(vector<vector<int>>&dif,int k,int x1,int y1,int x2,int y2,int k)
{
    dif[x1][y1]+=k;
    dif[x2+1][y2+1]+=k;
    dif[x1][y2+1]-=k;
    dif[x2+1][y1]-=k;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}