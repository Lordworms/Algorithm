#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>d1(n),d2(d1);
  for(int i=0;i<n;++i)cin>>d1[i];
  for(int i=0;i<n;++i)cin>>d2[i];
  auto match=[&](ll dis)
  {
    int p1=0,p2=dis;
    multiset<int,greater<int>>s[2];
    for(auto d:d1)s[0].insert(d);
    for(auto d:d2)s[1].insert(d);
    auto check=[&](int lim)
    {
      int ss1=s[0].empty()?-1:*s[0].begin(),ss2=s[1].empty()?-1:*s[1].begin();
      return ss1>lim||ss2>lim;
    };
    auto fetch=[&](int lim)
    {
        int ss1=s[0].empty()?-1:*s[0].begin(),ss2=s[1].empty()?-1:*s[1].begin();
        return ss1>ss2;
    };
    int cur,tmp;
    vector<int>ans;
    while(check(dis))
    {
      cur=fetch(dis)?0:1;
      tmp=*s[cur].begin();
      if(!(s[cur^1].count(tmp-dis)))//did not have a value responed to
      {
        return false;
      }
      s[cur].erase(s[cur].find(tmp));
      s[cur^1].erase(s[cur^1].find(tmp-dis));
      if(cur)
      {
        ans.push_back(p2-tmp);
      } 
      else
      {
        ans.push_back(p1+tmp);
      } 
    }
    vector<int>rem1,rem2;
    for(auto& k:s[0])rem1.push_back(k);
    for(auto& k:s[1])rem2.push_back(k);
    sort(rem1.begin(),rem1.end());
    sort(rem2.rbegin(),rem2.rend());
    for(int i=0;i<rem1.size();++i)
    {
        if(rem1[i]+rem2[i]!=dis)
        {
            return false;
        }
        ans.push_back(rem1[i]);
    }
    sort(ans.begin(),ans.end());
    if(ans[0]<=0)
    {
        int inc=-ans[0];
        for(int i=0;i<ans.size();++i)
        {
            ans[i]+=inc;
        }
        p1+=inc,p2+=inc;
    }
    cout<<"YES"<<'\n';
    for(auto& h:ans)
    {
        cout<<h<<' ';
    }
    cout<<'\n';
    cout<<p1<<' '<<p2<<'\n';
    return true;
  };
  for(auto& d:d2)
  {
    if(match(d1[0]+d)||match(abs(d1[0]-d)))
    {
        return;
    }
  }
  cout<<"NO"<<'\n';
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