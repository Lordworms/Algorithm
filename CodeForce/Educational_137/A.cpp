#include <bits/stdc++.h>
using namespace std;
int C[11][11];
void solve()
{
    int n;
    cin>>n;
    int x;for(int i=0;i<n;++i)cin>>x;
    cout<<C[4][2]*C[10-n][2]<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  memset(C,0,sizeof(C));
  for(int i=0;i<=10;++i)
  {
    for(int j=0;j<=i;++j)
    {
        if(j==0)C[i][j]=1;
        else C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
  }
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}