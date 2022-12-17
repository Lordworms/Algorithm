#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define LIM 100
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    vector<string>st;
    for(int i=0;i<s.size();++i)
    {
        int uni=0;
        unordered_map<int,ll>mp;
        for(int j=0;j<LIM&&i+j<s.size();++j)
        {
            auto index=s[i+j]-'0';
            if(!mp.count(index))++uni;
            mp[index]++;
            bool flag=true;
            for(auto k:mp)
            {
                if(k.second>uni)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)++ans;
        }
    }
    cout<<ans<<'\n';
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