#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=1e6+100;
double Q[MAXN];
double len[MAXN];
const int MOD=1e9+7;
void solve()
{
  int n;
  scanf("%d",&n);
  vector<double>a(n+1);
  int p=0;
  for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
  for(int i=1;i<=n;++i)
  {
    Q[++p]=a[i];
    len[p]=1;
    while(p>1&&Q[p]<Q[p-1])
    {
        Q[p-1]=(Q[p]*len[p]+Q[p-1]*len[p-1])/(len[p]+len[p-1]);
        len[p-1]+=len[p];
        --p;
    }
  }
  for(int i=1;i<=p;++i)
  {
    for(int j=0;j<len[i];++j)
    {
       printf("%.8lf\n",Q[i]);
    }
  }
  cout<<'\n';
  return;
}
int main()
{
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}