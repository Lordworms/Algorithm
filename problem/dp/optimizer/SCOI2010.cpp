/*
一共有四种转移
前两种已经写在注释里面了，现在来讲第三种和第四种
3.在第i天买入
dp[i][j]=max(dp[i-W-1][k]-(j-k)*ap)(j>=k)
        =max(dp[i-W-1][k]-j*ap+k*ap)
        =max(dp[i-W-1][k]+k*ap)-j*ap//而前半部分显然可以用单调队列
4.在第i天卖出
dp[i][j]=max(dp[i-W][k]+(k-j)*bp)(k>=j)
        =max(dp[i-W][k]+k*bp)-j*bp
        同样可以单调队列优化一哈
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e3+10;
int dp[MAXN][MAXN];
int l,r,q[MAXN],W,MAXP,T;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>T>>MAXP>>W;
  int as,ap,bs,bp;
  memset(dp,128,sizeof(dp));
  for(int i=1;i<=T;++i)
  {
    cin>>ap>>bp>>as>>bs;
    //第一种转移,空买入
    for(int j=0;j<=as;++j)dp[i][j]=-ap*j;//注意这里是as
    //第二种转移，啥都不干
    for(int j=0;j<=MAXP;++j)dp[i][j]=max(dp[i][j],dp[i-1][j]);
    if(i<=W)continue;//没法从之前的时候转移
    //买入的转移
    l=0,r=-1;
    for(int j=0;j<=MAXP;++j)
    {
        while(l<=r&&q[l]<j-as)++l;
        while(l<=r&&dp[i-W-1][q[r]]+q[r]*ap<dp[i-W-1][j]+j*ap)--r;
        q[++r]=j;
        dp[i][j]=max(dp[i][j],dp[i-W-1][q[l]]+q[l]*ap-j*ap);
    }
    l=0,r=-1;
    for(int j=MAXP;j>=0;--j)//这次要从大到小转移，所以从大到小枚举
    {
        while(l<=r&&q[l]>j+bs)++l;
        while(l<=r&&dp[i-W-1][q[r]]+q[r]*bp<dp[i-W-1][j]+j*bp)--r;
        q[++r]=j;
        dp[i][j]=max(dp[i][j],dp[i-W-1][q[l]]+q[l]*bp-j*bp);
    }
  }
  cout<<*max_element(dp[T],dp[T]+MAXP);
  return 0;
}