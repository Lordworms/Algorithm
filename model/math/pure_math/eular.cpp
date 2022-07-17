/*
    欧拉函数：什么是欧拉函数呢？我们记φ(n)为小于x且和x互质的数的数量，那么φ(n)就是欧拉函数
    φ(n)=n*(1-1/p1)(1-1/p2)(1-1/p3)*(1-1/p4)……(1-1/pn)
    
*/
#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int eular(int x)
{
    int ans=x;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
          ans=ans/i*(i-1);
          while(x%i==0)x/=i;
        }        
    }
    if(x>1)ans=ans/x*(x-1);
    return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}