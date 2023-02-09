#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1);
  map<int,int>mp;
  for(int i=1;i<=n;++i)cin>>a[i], mp[a[i]]++;
  int cur=0;
  vector<int>rem;
  for(int i=1;i<=n;++i)
  {
    cur+=mp[i];
    if(mp[i]>2||cur>i)
    {
        cout<<"NO\n";
        return;
    }
    if(!mp[i])rem.push_back(i);
  }
  vector<int>b(n+1),c(n+1);
  map<int,int>st;
  for(int i=1;i<=n;++i)
  {
    if(mp[a[i]]==1)
    {
        b[i]=c[i]=a[i];
    }
    else
    {
        if(!st.count(a[i]))
        {
            auto it=lower_bound(rem.begin(),rem.end(),a[i]);
            if(it==rem.begin())
            {
                cout<<"NO\n";
                return;
            }
            --it;
            b[i]=*it;
            c[i]=a[i];
            st[a[i]]=b[i];
            rem.erase(it);
        }
        else
        {
            b[i]=a[i];
            c[i]=st[a[i]];
        }   
    }
  }
  cout<<"YES\n";
  for(int i=1;i<=n;++i)cout<<b[i]<<" \n"[i==n];
  for(int i=1;i<=n;++i)cout<<c[i]<<" \n"[i==n];
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