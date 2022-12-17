#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
 ll n,z,o;
 cin>>n;
 string s;
 cin>>s;
 z=0,o=0;
 for(int i=0;i<n;i++)
 {
    if(s[i]=='1')
        o++;
    if(s[i]=='0')
        z++;
 }
 ll l=(1<<o);
 ll u=(1<<n)-(1<<z)+1;
 for(ll i=l;i<=u;i++)
 cout<<i<<" ";
 cout<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  

    solve();
  
  return 0;
}