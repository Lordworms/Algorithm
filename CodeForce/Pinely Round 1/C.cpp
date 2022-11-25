#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>>mp(n,vector<int>(n));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            char c;
            cin>>c;
            int x=c-'0';
            if(x)
            {
                mp[j][i]=1;
            }
        }
        mp[i][i]=1;
    }
    vector<vector<int>>ans(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                mp[i][j]|=(mp[i][k]&mp[k][j]);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        vector<int>ans;
        for(int j=0;j<n;++j)
        {
            if(mp[i][j])
            {
                ans.push_back(j+1);
            }
        }
        cout<<ans.size()<<" ";
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
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