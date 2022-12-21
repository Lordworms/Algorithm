/*
    we could use a map to store all the cnt of ai


*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>cnt(x+1);
    bool flag=false;
    for(int i=0;i<n;++i)
    {
        int k;
        cin>>k;
        if(k>x)
        {
            flag=true;
        }
        else
        {
            cnt[k]++;
        }
    }
    for(int i=1;i<x;++i)
    {
        if(cnt[i]%(i+1))
        {
            flag=true;
            break;
        }
        cnt[i+1]+=cnt[i]/(i+1);
    }
    if(flag)
    {
        cout<<"NO"<<'\n';
    }
    else
    {
        cout<<"YES"<<'\n';
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
  solve();
  return 0;
}