#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n;
  string s;
  cin>>n;
  cin>>s;
  unordered_map<string,int>st;
  string last="";
  for(int i=0;i<n-1;++i)
  {
    auto sub=s.substr(i,2);
    if(sub!=last|| (st.count(sub)&&st[sub]>=2))
    {
        if(st.find(sub)!=st.end())
        {
            cout<<"YES"<<'\n';
            return;
        }
    }
    st[sub]++;
    last=sub;
  }
  cout<<"NO"<<"\n";
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