/*
    尺取法
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;

  auto check=[&](char c)
  {
    int l=0,r=0,cnt=0,ans=0;
    while(r<n)
    {
        if(s[r]!=c)
        {
            if(cnt>=k)
            {
                while(s[l++]==c);
            }
            else
            {
                ++cnt;
            }
        }
        ans=max(ans,r-l+1);
        ++r;
    }
    return ans;
  };    
  cout<<max(check('a'),check('b'))<<'\n';
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