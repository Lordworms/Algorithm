#include <bits/stdc++.h>
using namespace std;
const int N=65;
const int mod=998244353;
vector<vector<int>>C(N,vector<int>(N,0));
void init()
{
    
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
  init();
  vector<int>F(N);
  F[1]=1;
  for(int i=2;i<=30;++i)
  {
    F[i]=(C[2*i-1][i-1]+(C[2*i-2][i-1]-1-F[i-1]+mod)%mod)%mod;
  }
  int t,x;
  cin>>t;
  while(t--)
  {
    cin>>x;
    int total=(C[x][x/2]-1-F[x/2]+mod)%mod;
    cout<<F[x/2]<<" "<<total<<" "<<1<<endl;
  }
  return 0;
}