#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    function<int(int,int)>gcd=[&](int a,int b)
    {
        return b?gcd(b,a%b):a;
    };
    vector<int>arr(n);
    int g=1;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        if(i==0)g=arr[i];
        g=gcd(g,arr[i]);
    }
    cout<<arr[n-1]/g+(arr[0]==0)<<'\n';
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