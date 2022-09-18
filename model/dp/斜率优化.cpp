/*
   用HNOI2008玩具装箱这道题来进行讲解，具体的自己可以看原题 
  注意都要用double
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;
const int MAXN=5e4+10;
int L,n;
db dp[MAXN],sum[MAXN];
int Q[MAXN];
inline db a(int i){return sum[i]+i;}
inline db b(int i){return a(i)+L+1;}
inline db X(int i){return b(i);}
inline db Y(int i){return dp[i]+b(i)*b(i);}
inline db slope(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n>>L;
  for(int i=1;i<=n;++i)
  {
    cin>>sum[i];
    sum[i]+=sum[i-1];
  }
  int l=1,r=1;
  for(int i=1;i<=n;++i)
  {
    while(l<r&&slope(Q[l],Q[l+1])<2*a(i))++l;
    dp[i]=dp[Q[l]]+(a(i)-b(Q[l]))*(a(i)-b(Q[l]));
    while(l<r&&slope(i,Q[r-1])<slope(Q[r-1],Q[r]))--r;
    Q[++r]=i;
  }
  cout<<(ll)dp[n]<<endl;
  return 0;
}