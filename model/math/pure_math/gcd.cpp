/*
本章包括普通gcd和扩展gcd
注意扩展gcd得出的x，y始终满足x<|a| y<|b|
如果是从原点出发，那么如果角度为45度的话，最后会在lcm(n,m)时间内收敛
*/
#include <bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int& x,int& y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}