/*
    we should find the first colum that the 0 pos element is different from the 1 pos.
    then traverse the L->R and R->L to get whether it would work

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{   
  int n;
  cin>>n;
  string st[2];
  cin>>st[0]>>st[1];
  int pos=-1;
  for(int i=0;i<n;++i)
  {
    if(st[0][i]!=st[1][i])
    {
        pos=i;
        break;
    }
  }
  if(pos==-1)
  {
    cout<<"YES"<<'\n';
    return;
  }
  bool flag=true;
  int cur=(st[0][pos]=='B'?0:1);
  for(int i=pos+1;i<n;++i)
  {
    if(st[cur][i]=='W')
    {
        flag=false;
        break;
    }
    if(st[cur^1][i]=='B')
    {
        cur^=1;
    }
  }
  cur=(st[0][pos]=='B'?0:1);
  for(int i=pos-1;i>=0;--i)
  {
    if(st[cur][i]=='W')
    {
        flag=false;
        break;
    }
    if(st[cur^1][i]=='B')
    {
        cur^=1;
    }
  }
  cout<<(flag?"YES":"NO")<<'\n';
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