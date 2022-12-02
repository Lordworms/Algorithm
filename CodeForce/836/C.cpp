/*
    a intuitive way to solve it is that the permutation is almost identity permutation
    so we just need to change some part of this array


*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>ans;
    for(int i=0;i<=n;++i)ans.push_back(i);
    ans[1]=x;
    ans[n]=1;
    if(n%x)
    {
        cout<<-1<<'\n';
        return;
    }
    if(n==x)
    {
        for(int i=1;i<=n;++i)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    ans[x]=n;
    for(int i=x+1;i<n;++i)
    {
        if(ans[i]%x==0&&ans[x]%i==0)
        {
            swap(ans[x],ans[i]);
            x=i;
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
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