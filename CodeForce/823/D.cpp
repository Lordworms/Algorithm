/*
    it is always possible to move any s[i] to position j
    the relative position of s1[i] and s2[n-i-1] are always the same
    so let's make them a pair{s1[i],s2[n-i-1]} , then we concider how to make 
    s1 and s2 equal
    if there are even number of pair, we could always do that 
    let us suppose the pair to be {a,b} {a,b}
    ...a.....b...
    ...a.....b...
    however, if the number is even, then it is impossible 
     ...a.....b...a
    ...a.....b...b
    and there is a exception,
    if there exist a single pair and the two number are equal
    {a,a}
    we could place it in a certain place(middle)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<char,char>;
void solve()
{
    int n;
    string s1,s2;
    cin>>n>>s1>>s2;
    map<pii,int>mp;
    for(int i=0;i<n;++i)
    {
        mp[make_pair(min(s1[i],s2[n-i-1]),max(s1[i],s2[n-i-1]))]++;
    }
    int cnt=0;
    for(auto p:mp)if(p.second%2)++cnt;
    for(auto p:mp)
    {
        if(p.second%2)
        {
            if(p.first.first!=p.first.second)++cnt;
        }
    }
    if(cnt>1)
    {
        cout<<"NO"<<'\n';
    }
    else
    {
        cout<<"YES"<<'\n';
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