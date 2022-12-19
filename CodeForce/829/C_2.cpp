#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;++i)cin>>arr[i];
  int sum=accumulate(arr.begin(),arr.end(),0);
  if(sum%2)
  {
    cout<<-1<<'\n';
    return;
  }
  if(sum==0)
  {
    cout<<n<<'\n';
    for(int i=0;i<n;++i)
    {
        cout<<i+1<<' '<<i+1<<'\n';
    }
    return;
  }
  using pii=pair<int,int>;
  vector<pii>ans;
  int sign=sum>0?1:-1;
  auto check=[&](int i)
  {
    return (arr[i]==0&&arr[i+1]==sign)||(arr[i]==sign&&arr[i+1]==sign)||(arr[i]==-sign&&arr[i+1]==sign);
  };
  //{0,1} {1,1}, {-1,1} would make the sum -=2
  //{0,-1} {1,-1},{-1,-1} would make the sum +=2
  for(int i=0;i<n;++i)
  {
    if(i<n-1&&check(i)&&sum!=0)
    {
        ans.push_back({i+1,i+2});
        sum-=(2*sign);
        ++i;
    }
    else
    {
        ans.push_back({i+1,i+1});
    }
  }
  cout<<ans.size()<<'\n';
  for(auto& k:ans)
  {
    cout<<k.first<<' '<<k.second<<'\n';
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