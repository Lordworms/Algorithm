#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n+1);
  unordered_set<int>st;
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    st.insert(a[i]);
  }
  int m=st.size();
  unordered_set<int>unused;
  for(int i=1;i<=n;++i)
  {
    if(!st.count(i))
    {
        unused.insert(i);
    }
  }
  unordered_set<int>used;
  vector<int>last_used(n+1);
  for(int i=1;i<=n;++i)
  {
    if(used.count(a[i]))
    {
        int tmp=a[i];
        a[i]=*(unused.begin());
        if(a[i]==i)
        {
            swap(a[i],a[last_used[tmp]]);
        }
        unused.erase(unused.begin());
    }
    else
    {
        used.insert(a[i]);
    }
    last_used[a[i]]=i;
  }
  cout<<used.size()<<'\n';
  for(int i=1;i<=n;++i)
  {
    cout<<a[i]<<" \n"[i==n];
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