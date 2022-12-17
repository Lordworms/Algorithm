#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+6;
int prime[MAXN],p[MAXN],cnt;//p stands for the biggest prim factor of i and prime stands for whether it is a prim
void init_prim()
{
    p[0]=p[1]=-1;
    for(int i=2;i<MAXN;++i)
    {
        if(!p[i])
        {
          prime[++cnt]=i;
          p[i]=i;  
        }
        for(int j=1;j<=cnt&&i*prime[j]<MAXN;++j)
        {
            p[i*prime[j]]=prime[j];
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}