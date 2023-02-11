#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  string s;
  cin>>s;
  string a,b,c;
  int n=s.size();
  for(int i=0;i<n;++i)
  {
    for(int j=i+1;j<n;++j)
    {
        for(int k=j+1;k<n;++k)
        {
            a=s.substr(i,j-i);
            b=s.substr(j,k-j);
            c=s.substr(k,n-k);
            if(b<=a&&b<=c||b>=a&&b>=c)
            {
                cout<<a<<' '<<b<<' '<<c<<'\n';
                return;
            }
        }
    }
  }
  cout<<":(\n";
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