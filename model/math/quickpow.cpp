#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int quickPow(int n,int exp)
{
    ll ans=0;
    while(exp)
    {
        if(exp&1)
        {
            ans*=n;
        }
        n*=n;
        exp>>=1;
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}