/*
  if n is odd:
      n is odd then 
  if n is even:
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>ans;
  if(n%2)//odd
  {
    for(int i=n-n/2;i<=n+n/2;++i)
    {
      ans.push_back(i+2);
    }
    ans[0]-=1;
    ans[ans.size()-1]+=1;
    ans[ans.size()-2]+=1;
  }
  else//even [n/2 n/2+1 .... n-1 n+1 ...3n/2]
  {
    for(int i=n/2;i<=n/2+n;i+=1)
    {
      if(i!=n)ans.push_back(i);
    }
  }
  for(int i=0;i<ans.size();++i)
  {
    cout<<ans[i]<<' ';
  }
  cout<<'\n';
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