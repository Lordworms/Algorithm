/*
    对于极差，要去想双指针！
    认真体会双指针！
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
void solve()
{
  int n,m;cin>>n>>m;
  int num=0;
  vector<int>a(n);
  vector<int>cnt(MAXN);
  for(int i=0;i<n;++i)cin>>a[i];
  sort(a.begin(),a.end());
  auto add=[&](int x)
  {
    if(x>=1&&x<=m)
    {
        ++cnt[x];
        if(cnt[x]==1)++num;
    }
  };
  auto sub=[&](int x)
  {
    if(x>=1&&x<=m)
    {
        --cnt[x];
        if(cnt[x]==0)--num;
    }
  };
  int l=0,r=-1;
  int ans=INT_MAX;
  for(;l<n;++l)
  {
    while(num<m)
    {
        if(r==n-1)break;
        for(int i=1;i*i<=a[r+1];++i)
        {
            if(a[r+1]%i==0)
            {
                add(i);
                if(a[r+1]/i!=i)
                {
                    add(a[r+1]/i);
                }
            }
        }
        ++r;
    }
    if(num==m)ans=min(ans,a[r]-a[l]);
    for(int i=1;i*i<=a[l];++i)
    {
        if(a[l]%i==0)
        {
            sub(i);
            if(a[l]/i!=i)
            {
                sub(a[l]/i);
            }
        }
    }
  }
  cout<<(ans==INT_MAX?-1:ans)<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}