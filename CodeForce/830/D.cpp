/*
    sigma(n/k)=nlog(n)
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    ll x;
    cin>>n;
    char c;
    map<ll,int>mp;//表示现在处理到哪里
    map<ll,int>exist;
    map<ll,set<ll>>mp1,mp2;//mp1表示，mp2表示
    while(n--)
    {
        cin>>c>>x;
        if(c=='+')
        {
          exist[x]++;//表示其在集合中
          if(mp1[x].size())//当前数会被影响
          {
            set<ll>::iterator it=mp1[x].begin();
            while(it!=mp1[x].end())
            {
                
                mp2[*it].erase(x);//x加入集合，无法再出现在答案中
                ++it;
            }
          }
        }
        if(c=='-')
        {    
          exist[x]--;//出集合
          if(mp1[x].size())
          {
            set<ll>::iterator it=mp1[x].begin();
            while(it!=mp1[x].end())
            {
                mp2[*it].insert(x);//mp1[x]里的数开始可以选择x了
                ++it;
            }
          }
        }
        else if(c=='?')
        {
          ll now;
          if(!mp[x])
          {
            mp[x]=1;
          }
          now=mp[x];
          while(exist[now*x])
          {
            mp1[now*x].insert(x);
            ++now;
          }
          ll ans=now*x;
          if(mp2[x].size())
          {
            ans=min(ans,*(mp2[x].begin()));
          }
          cout<<ans<<'\n';
          mp[x]=now;
        }   
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
  solve();
  return 0;
}