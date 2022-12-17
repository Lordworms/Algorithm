#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  auto query=[&](int x,int y)
  {
    cout<<"? "<<x<<' '<<y<<'\n';
    int k;
    cout.flush();
    cin>>k;
    return k;
  };
  auto report=[&](int x,int y)
  {
    cout<<"! "<<x<<" "<<y<<'\n';
    cout.flush();
    int k;cin>>k;
  };
  int n;
  cin>>n;
  vector<int>arr;
  for(int i=1;i<=n;++i)arr.push_back(i);
  while(arr.size()>2)
  {
    int a=arr.back();
    arr.pop_back();
    int b=arr.back();
    arr.pop_back();
    int c=arr.back();
    arr.pop_back();
    int q1=query(a,b),q2=query(b,c);
    if(q1==q2)
    {
      arr.push_back(a);
      arr.push_back(c);
    }
    else if(q1<q2)
    {
      arr.push_back(b);
      arr.push_back(c);
    }
    else
    {
      arr.push_back(a);
      arr.push_back(b);
    }
  }
  report(arr[0],arr[1]);
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  //freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  //freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}