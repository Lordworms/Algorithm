/*
本章包括普通gcd和扩展gcd
注意扩展gcd得出的x，y始终满足x<|a| y<|b|
如果是从原点出发，那么如果角度为45度的话，最后会在lcm(n,m)时间内收敛
注意如果要求出最小正整数解：
  证明过程：
    a*x1+b*y1=gcd(a,b)
    a*x2+b*y2=gcd(a,b)
    a*(x1-x2)=b*(y1-y2)
    令A=a/gcd(a,b) B=b/gcd(a,b)
    A(x1-x2)=B*(y1-y2)
    A*(nB)=B*(mA)
    x1-x2=nB
    y1-y2=mA
    x1=x2+nB
    所以x的通解公式为x=x0+nB
    所以我们得出的值一直modB即可
    https://www.cnblogs.com/qiyueliu/p/11691582.html
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