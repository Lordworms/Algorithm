#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct node
{
    int num,pos;
};
void solve()
{
  string s;
  cin>>s;
  int n=s.size();
  vector<node>arr(s.size());
  for(int i=0;i<n;++i)
  {
    arr[i].num=s[i];
    arr[i].pos=i;
  }
  sort(arr.begin(),arr.end(),[&](node a,node b)
  {
    if(a.num==b.num)
    {
        return a.pos>b.pos;
    }
    return a.num<b.num;
  });
  vector<int>less(s.size(),n);
  int mini=n-1,minv=s.back();
  for(int i=n-1;i>=0;--i)
  {
    if(minv<s[i])
    {
        less[i]=mini;
    }
    else
    {
        mini=i,minv=s[i];
        less[i]=n;
    }
  }
  for(int i=0;i<n;++i)
  {
    if(less[arr[i].pos]==n)
    {
        cout<<arr[i].num-'0';
    }
    else
    {
        auto v=arr[i].num-'0'+1;
        if(v>=10)v=9;
        cout<<v;
    }
  }
  cout<<'\n';
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