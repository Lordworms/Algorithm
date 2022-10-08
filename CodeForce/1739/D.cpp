/*
  注意这里pi<i这个条件！
  草泥马！

*/
#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve()
{
  cin>>n>>k;
  vector<int>p(n);
  for(int i=1;i<n;++i)
  {
    cin>>p[i];
    --p[i];
  }
  int l=0,r=n,m;
  while(l+1!=r)
  {
    m=(l+r)>>1;
    vector<int>h(n);
    int now=0;
    for(int i=n-1;i>0;--i)
    {
      if(h[i]==m-1&&p[i]!=0)//注意这个m-1，然后要记住这里是0-n
      {
        ++now;
      }
      else
      {
        h[p[i]]=max(h[p[i]],h[i]+1);
      }
    }
    if(now>k)//数越小，对应第一种情况：找第一个>=5的元素
    {
      l=m;
    }
    else
    {
      r=m;
    }
  }
  cout<<r<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("/Users/xiangyanxin/code/Algorithom/CodeForce/1739/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/CodeForce/1739/out.txt","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}