/*
题解：
  通过这题完全弄懂这个平面扩展点的问题
  一个点(x,y)如果把它展开到无限的矩形平面，那么对应的坐标是啥呢？2kn+-x/2tm+-y 我们连接这两个等式，然后我们用exgcd算出解就可以了
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    y=
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}