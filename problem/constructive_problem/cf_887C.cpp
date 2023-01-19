#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  vector mp(7,vector<int>(7,0));
  int same=0;
  for(int i=0;i<6;++i)
  {
    unordered_set<int>st;
    for(int j=0;j<4;++j)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    if(st.size()==1)++same;
    else if(st.size()==2)
    {
        int p=-1,pp=-1;
        for(auto s:st)
        {
            if(p==-1)p=s;
            else pp=s;
        }
        if(p>pp)swap(p,pp);
        mp[p][pp]++;
    }
    else
    {
        cout<<"NO"<<'\n';
        return;
    }
  }
  if(same==2)
  {
    for(int i=1;i<7;++i)
    {
        for(int j=1;j<7;++j)
        {
            if(mp[i][j]>1)
            {
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    cout<<"YES\n";
  }
  else
  {
    cout<<"NO"<<'\n';
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}