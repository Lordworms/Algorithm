#include <bits/stdc++.h>
using namespace std;
int f[1000],n,mod=1;
//(ai-x)的阶乘的对应香系数
void getF()
{
     for(int i=0;i<n;++i)
  {
    cin>>x;
    for(int j=i;j;--j)
    {
        f[j]=(f[j]*x%mod-f[j-1]+mod)%mod;
    }
    f[0]=f[0]*x%mod;
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}