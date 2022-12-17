#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MAXN=4e4+10;
int prime[MAXN],p[MAXN],cnt;//p stands for the biggest prim factor of i and prime stands for whether it is a prim
void init_prim()
{
    p[0]=p[1]=-1;
    for(int i=2;i<MAXN;++i)
    {
        if(!p[i])
        {
          prime[++cnt]=i;
          p[i]=i;  
        }
        for(int j=1;j<=cnt&&i*prime[j]<MAXN;++j)
        {
            p[i*prime[j]]=prime[j];
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}
void solve()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  int maxN=0;
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
    maxN=max(arr[i],maxN);
  }
  for(int i=1;i<=cnt&&prime[i]<=maxN;++i)
  {
    int t=0;
    for(int j=0;j<n;++j)
    {
        if(arr[j]%prime[i]==0)
        {
            ++t;
            if(t>=2)
            {
                cout<<"YES"<<'\n';
                return;
            }
            while(arr[j]%prime[i]==0)arr[j]/=prime[i];
        }
    }
  }
  unordered_set<int>st;
  for(int i=0;i<n;++i)
  {
    if(st.count(arr[i])&&arr[i]!=1)
    {
        cout<<"YES"<<'\n';
        return;
    }
    if(arr[i]!=1)st.insert(arr[i]);
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
  init_prim();
  while(T--)
  {
    solve();
  }
  return 0;
}