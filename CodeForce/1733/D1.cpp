/*
    没有x和y的大小限制，那么当x<y的时候，我们之前的结果还是适用的
*/
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const i64 INF=1e18;
int T,n,x,y;
void solve()
{
    cin>>n>>x>>y;
    vector<int>arr(n);char ch;
    for(int i=0;i<n;++i)
    {
        cin>>ch;
        arr[i]=ch-'0';
    }
    
    int cnt=0;
    vector<int>pos;
    for(int i=0;i<n;++i)
    {
        cin>>ch;
        arr[i]^=ch-'0';
        if(arr[i])
        {
            ++cnt;
            pos.push_back(i);
        }
    }
    if(cnt%2)
    {
        cout<<-1<<endl;
        return;
    }
    if(x>=y)
    {
        if(cnt!=2||pos[0]+1<pos[1])
        {
            cout<<1LL*cnt/2*y<<endl;
            return;
        }
        if(pos[0]>1||pos[1]<n-2)
        {
            cout<<min(1LL*x,2LL*y)<<endl;
            return;
        }
        else if(n>=4)
        {
            cout<<min(1LL*x,3LL*y)<<endl;
        }
        cout<<x<<endl;
        return;
    }
    else
    {
        int N=pos.size();
        vector<i64>dp(N+1,INF);//dp表示前i个元素的最小代价
        //dp[i]=min(dp[j])+
        dp[0]=0;
        for(int i=0;i<N;i+=2)
        {
            i64 cur=0;
            for(int j=i+2;j<=N;j+=2)
            {
                if(j>=i+4)
                {
                    cur+=1LL*x*(pos[j-2]-pos[j-3]);//仔细体会
                }
                dp[j]=min(dp[j],dp[i]+min(1LL*y,1LL*x*(pos[j-1]-pos[i]))+cur);
            }
        }
        cout<<dp[N]<<endl;
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}