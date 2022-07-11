/*
并查集板子
*/
#include <bits/stdc++.h>
using namespace std;
int MAXN=1e5+5;
vector<int>fa(MAXN,-1);
vector<int>t_size(MAXN,1);
int getFa(int x)
{
    if(x!=fa[x])fa[x]=getFa(fa[x]);
    return fa[x];
}
int merge(int x,int y)//把x的爹变成y的爹,也就是把x和y连接起来，然后
{
    x=getFa(x),y=getFa(y);
    if(x==y)return t_size[x];
    fa[x]=y;
    t_size[y]+=t_size[x];
    return t_size[x]+t_size[y];
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}