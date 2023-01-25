#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct node
{
    int id,val;
};
void solve()
{
  auto query=[&](string s)
  {
    cout<<"? "<<s<<'\n';
    int cap;
    cin>>cap;
    cout.flush();
    return cap;
  };
  auto report=[&](int s)
  {
    cout<<"! "<<s<<'\n';
  };
  int n,m;
  cin>>n>>m;
  string s(m,'0');
  vector<node>E(m);
  for(int i=0;i<m;++i)
  {
    s[i]='1';
    E[i]={i,query(s)};
    s[i]='0';
  }
  sort(E.begin(),E.end(),[&](node a ,node b)
  {
        return a.val<b.val;
  });
  fill(s.begin(),s.end(),'0');
  int ans=0;
  for(int i=0;i<m;++i)
  {
    s[E[i].id]='1';
    if(query(s)==ans+E[i].val)
    {
        ans+=E[i].val;
    }
    else
    {
        s[E[i].id]='0';
    }
  }
  report(ans);
  return;
}
int main()
{
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}