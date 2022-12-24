/*
    we could get the four array ll,lr,gl,gr which represent:first element less than or equal to a[i] on its left, less than a[i] on its right, greater than a[i] on its left greater than a[i] on its right
     
     we preset the factor of every element
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int LIM=1e6+100;
vector<int>fac[LIM];
vector<int>pos[LIM];
vector<int>idx(LIM,0);
void init()
{
    for(int i=1;i<LIM;++i)
    {
        for(int j=i;j<LIM;j+=i)
        {
            fac[j].push_back(i);
        }
    }
}
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n+1);
  for(int i=1;i<=n;++i)
  {
    cin>>arr[i];
    pos[arr[i]].push_back(i);
  }
  vector<int>ll(n+1),lr(n+1),gl(n+1),gr(n+1);
  vector<int>s;
  for(int i=1;i<=n;++i)
  {
    while(s.size()&&arr[s.back()]>=arr[i])s.pop_back();
    if(!s.size())ll[i]=0;
    else ll[i]=s.back();
    s.push_back(i);
  }
  s.clear();
  for(int i=n;i>=1;--i)
  {
    while(s.size()&&arr[s.back()]>=arr[i])s.pop_back();
    if(!s.size())lr[i]=n+1;
    else lr[i]=s.back();
    s.push_back(i);
  }
  s.clear();
  for(int i=1;i<=n;++i)
  {
    while(s.size()&&arr[s.back()]<arr[i])s.pop_back();
    if(!s.size())gl[i]=0;
    else gl[i]=s.back();
    s.push_back(i);
  }
  s.clear();
  for(int i=n;i>=1;--i)
  {
    while(s.size()&&arr[s.back()]<=arr[i])s.pop_back();
    if(!s.size())gr[i]=n+1;
    else gr[i]=s.back();
    s.push_back(i);
  }
  long long ans=0;
  for(int i=1;i<=n;++i)
  {
    for(int x:fac[arr[i]])
    {
        if(idx[x]>0)//j on i's left
        {
            int j=pos[x][idx[x]-1];
            if(j>gl[i]&&i<lr[j])
            {
                ans+=1ll*(j-max(gl[i],ll[j]))*((min(gr[i],lr[j])-i));
            }
        }
        if(idx[x]<pos[x].size())//j on i's right
        {
            int j=pos[x][idx[x]];
            if(j<gr[i]&&i>ll[j])
            {
                ans+=1ll*(i-max({gl[i],ll[j],idx[x]>0?pos[x][idx[x]-1]:0}))*(min(gr[i],lr[j])-j);//do not count twice
            }
        }
    }
    ++idx[arr[i]];
  }
  cout<<ans<<'\n';
  for(int i=1;i<=n;++i)
  {
    pos[arr[i]].clear();
    idx[arr[i]]=0;
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
  init();
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}