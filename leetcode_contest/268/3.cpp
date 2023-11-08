#include <bits/stdc++.h>
using namespace std;
int maxTrailingZeros(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>h2(m+1),h5(m+1),v2(m+1),v5(m+1);
    for(int i=0;i<=m;++i)h2[i]=h5[i]=v2[i]=v5[i]=vector<int>(n+1);
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int x=grid[i-1][j-1];
            int two=0,five=0;
            while(x%2==0)two++,x/=2;
            while(x%5==0)five++,x/=5;
            h2[i][j]=h2[i][j-1]+two;
            v2[i][j]=v2[i-1][j]+two;
            h5[i][j]=h5[i][j-1]+five;
            v5[i][j]=v5[i-1][j]+five;
        }
    }
    int ans=0;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            ans=max(ans,min(h2[i][j]+v2[i-1][j],h5[i][j]+v5[i-1][j]));
            ans=max(ans,min(h2[i][j]+v2[m][j]-v2[i][j],h5[i][j]+v5[m][j]-v5[i][j]));
            ans=max(ans,min(h2[i][n]-h2[i][j]+v2[i][j],h5[i][n]-h5[i][j]+v5[i][j]));
            ans=max(ans,min(h2[i][n]-h2[i][j]+v2[m][j]-v2[i-1][j],h5[i][n]-h5[i][j]+v5[m][j]-v5[i-1][j]));
        }
    }
    return ans;
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   return 0;
}
