/*
    classic problem: if all t is equal to 0, then the solution is (xmax+xmin)>>1
    we want those who stands on
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>pos(n),t(n);
  for(int i=0;i<n;++i)cin>>pos[i];
  for(int i=0;i<n;++i)cin>>t[i];
  int maxT=*max_element(t.begin(),t.end());
  int minP=INT_MAX,maxP=INT_MIN;
  for(int i=0;i<n;++i)
  {
    int seg=(maxT-t[i]);
    minP=min(minP,pos[i]+seg);//向右走的最小值
    maxP=max(maxP,pos[i]-seg);//向左走的最大值
  }
  cout<<(maxP+minP)/2;
  if((maxP+minP)%2)
  {
    cout<<".5";
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