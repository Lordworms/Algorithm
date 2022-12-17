/*
    dp[u][x] means the root is u and value is x, get the way to ditribute all elements
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=2e5+10;
const int MOD=1e9+7;
vector<int>arr;
vector<vector<int>>st;
vector<int>lg;
vector<vector<ll>>dp;
vector<vector<ll>>sum;
int n,m;
int query(int l,int r)
{
    if(arr[st[l][lg[r-l+1]]]>=arr[st[r-(1<<lg[r-l+1])+1][lg[r-l+1]]])
    {
        return st[l][lg[r-l+1]];
    }
    else 
    {
        return st[r-(1<<lg[r-l+1])+1][lg[r-l+1]];
    }
}
void init_lg()
{
    lg.resize(MAXN+1);
    lg[0]=lg[1]=0;
    for(int i=2;i<=MAXN;++i)lg[i]=lg[i/2]+1;
}
void init_st()
{
    for(int i=0;i<arr.size();++i)st[i][0]=i;
    for(int j=1;j<=lg[arr.size()];++j)
    {
        for(int i=0;i+(1<<j)<=arr.size();++i)
        {
            if(arr[st[i][j-1]]>=arr[st[i+(1<<(j-1))][j-1]])
            {
                st[i][j]=st[i][j-1];
            }
            else
            {
                st[i][j]=st[i+(1<<(j-1))][j-1];
            }
        }
    }
}
int dfs(int l,int r)
{
    if(l>r)return -1;
    int mid=query(l,r);
    int bef=dfs(l,mid-1),aft=dfs(mid+1,r);
    for(int x=1;x<=m;++x)
    {
        if(bef!=-1&&x==1)dp[mid][1]=0;
        else
        {
            dp[mid][x]=(bef>=0?sum[bef][x-1]:1)*(aft>=0?sum[aft][x]:1)%MOD;
        }
        sum[mid][x]=(sum[mid][x-1]+dp[mid][x])%MOD;
    }
    return mid;
}
void solve()
{
    cin>>n>>m;
    dp.resize(n);
    sum.resize(n);
    arr.resize(n);
    st=vector<vector<int>>(arr.size()+1,vector<int>(lg[arr.size()]+1));
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        st[i][0]=i;
        dp[i].resize(m+1,0);
        sum[i].resize(m+1,0);
    }
    init_st();
    dfs(0,n-1);
    auto key=query(0,n-1);
    cout<<sum[key][m]<<'\n';
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
  init_lg();
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}