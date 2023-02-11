#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  string s,a,b,c;
  cin>>s;
  string d=s.substr(0,2);
  int n=s.size();
  if(d=="aa"||d=="bb"||d=="ba")
  {
    a+=s[0];
    b+=s[1];
    c=s.substr(2,n);
  }
  else
  {
    string sb=s.substr(1,n-2);
    int index=sb.find('a');
    if(index==-1)
    {
        a+=s[0];
        c+=s[n-1];
        b=sb;
    }
    else
    {
        a+=s[0];
        c=sb.substr(index,sb.size()-index+1)+s[n-1];
        b=sb.substr(0,index);
    }
  }
  cout<<a<<' '<<b<<' '<<c<<'\n';
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