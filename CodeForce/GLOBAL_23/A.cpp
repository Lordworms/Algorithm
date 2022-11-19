#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,k;
    cin>>n>>k;
    int x;
    bool flag=false;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        if(x==1)
        {
            flag=true;
        }
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}