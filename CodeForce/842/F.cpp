/*
    if max{ai...aj}*(j-i)<min{ai...aj}*(j-i)^2, then we should jump one by one
    3 different situation
    1. amin>=sqrt(amax)
        j-i<=sqrt(amax) holds
        then we  should iterate j-sqrt(amax) to j-1 to update the answer
    2. amin<sqrt(amax)
        it could always proof that using the min value of {ai ... aj}(let's say ak) to be the transaction point is betetr
        proof:
            ak*(j-k)^2+ak*(k-i)^2<=ak*(j-i)^2
            (j-k)^2+(k-i)^2<=(j-i)^2
            a^2+b^2<=(a+b)^2
        a.i==k
            just maintain a rightmost array which holds a 
        b.j==k
            iterate from j-1 to 0, once a[i]<=a[j] we break
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int SRT=650;
void solve()
{
  int n;
  cin>>n;
  vector<ll>a(n);
  vector<ll>dp(n,1e18);
  for(int i=0;i<n;++i)cin>>a[i];
  ll amax=*max_element(a.begin(),a.end());
  dp[0]=0;
  vector<int>st={0};
  for(int i=1;i<n;++i)
  {
    ll amin=a[i];
    for(int j=i-1;j>=max(i-SRT,0);--j)
    {
        amin=min(a[j],amin);
        dp[i]=min(dp[i],dp[j]+amin*(i-j)*(i-j));
    }
    if(a[i]<=SRT)//mina[i..j]=a[j]
    {
        for(int j=i-1;j>=0;--j)
        {
            dp[i]=min(dp[i],dp[j]+a[i]*(i-j)*(i-j));
            if(a[j]<=a[i])break;
        }
    }
    for(int j:st)
    {
        dp[i]=min(dp[i],dp[j]+a[j]*(i-j)*(i-j));
    }
    if(a[i]<=SRT)//mina[i...j] =a[i]
    {
        while(st.size()&&a[st.back()]>=a[i])st.pop_back();//维护一个<=SRT且递减的单调栈即可
        st.push_back(i);
    }

  }
  for(int i=0;i<n;++i)
  {
    cout<<dp[i]<<" \n"[i==n-1];
  }
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}