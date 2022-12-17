#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  int st;
  cin>>st;
  vector<int>arr(n-1);
  for(int i=0;i<n-1;++i)cin>>arr[i];
  sort(arr.begin(),arr.end());
  int beg=lower_bound(arr.begin(),arr.end(),st)-arr.begin();
  if(beg>=arr.size())
  {
    cout<<st<<'\n';
  }
  else
  {
    for(int i=beg;i<arr.size();++i)
    {
        if(arr[i]<=st)
        {
            continue;
        }
        st=(st+arr[i]+1)/2;
    }
    cout<<st<<'\n';
  }
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