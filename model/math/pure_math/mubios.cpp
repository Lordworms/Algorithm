/*
莫比乌斯反演板子
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
//linear solution
int mu[MAXN],prim[MAXN];
bool flag[MAXN];
void getMu(int n){
  mu[1]=1;
  int cnt=0;
  memset(flag,false,sizeof(flag));
  for(int i=2;i<=n;++i)
  {
    if(!flag[i])prim[cnt++]=i,mu[i]=-1;
    for(int j=0;j<cnt&&i*prim[j]<=n;++j)
    {
        flag[i*prim[j]]=true;
        if(i%prim[j]==0)
        {
          mu[i*prim[j]]=0;
          break;
        }
        mu[i*prim[j]]=-mu[i];
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}