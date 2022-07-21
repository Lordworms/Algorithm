/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
int quick_mul(int a,int b,int mod)
{
    int ans=0;
    while(b)
    {
        if(b&1)ans=(ans+a%mod)%mod;
        b>>=1;
        a=(a+a)%mod;
    }
    return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}