/*
题意：
    给你n个点m条边，你每次可以把链接(u,v)的边i变成(u,t),其中，t是直接和v相连的一条边，求从1到n的最小代价
题解：
    我们总是可以把1和n链接起来,另dis[u][v]为从u到v经过的点的数量
    连接的方式有两种
    1. 1-u v-n u-v
    这种情况
    2. 1-x x-n


*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{

}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  
  return 0;
}