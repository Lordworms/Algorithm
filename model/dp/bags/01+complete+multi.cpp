/*
  1.我们按照j对v的模数来进行分类
  那么对应的解就如下所示
  dp[j]=max{dp[j-v]+w,dp[j-2*v]+2*w.....dp[j-k*v]+k*w}
  改写一下
  dp[j+kv]=max{dp[j],dp[j+1*v]-w,dp[j+2*v]-2*w....dp[j+k*v]-k*w}+k*w
  下面的k就是这里的j+kv
  所以比较的时候直接比较(k-j)/v*w和(q[l]-j)/v*w;
  转化为经典的单调队列问题，即在num的范围内求出最值
  单调队列从尾到头递增！！！
  单调队列从尾到头递增！！！
  单调队列从尾到头递增！！！
  单调队列从尾到头递增！！！
  单调队列从尾到头递增！！！
  单调队列从尾到头递增！！！
  单调队列从尾到头递增！！！

*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int dp[MAXN],pre[MAXN];
int m,n;
int q[MAXN];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>m;
  int v,w,num;
  for(int i=0;i<n;++i)
  {
    cin>>v>>w>>num;
    memcpy(pre,dp,sizeof(dp));
    for(int j=0;j<v;++j)
    {
      int l=0,r=-1;
      for(int k=j;k<=m;k+=v)
      {
        dp[k]=pre[k];
        while(l<=r&&k-num*v>q[l])++l;
        while(l<=r&&pre[k]-(k-j)/v*w>=pre[q[r]]-(q[r]-j)/v*w)--r;
        if(l<=r)dp[k]=max(dp[k],pre[q[l]]+(k-q[l])/v*w);
        q[++r]=k;
      }
    }
  }
  cout<<dp[m]<<endl;
  return 0;
}