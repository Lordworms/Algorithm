#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  cin>>n;
  vector<int>a(n);
  int ans=0;
  for(int i=0;i<n;++i)cin>>a[i];
  for(int k=1;k<=n;++k)
  {
    multiset<int>st(a.begin(),a.end());
    for(int i=0;i<k;++i)
    {
        auto it=upper_bound(st.begin(),st.end(),k-i);
        if(it==st.begin())break;
        st.erase(--it);
        if(!st.empty())
        {   
            int x=*(st.begin());
            st.erase(st.begin());
            st.insert(x+k-i);
        }
    }
    if(st.size()+k==n)ans=k;
  }
  cout<<ans<<'\n';
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