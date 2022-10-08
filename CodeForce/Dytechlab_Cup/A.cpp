#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve()
{
   int n,k;
   cin>>n>>k;
   map<char,int>mp;
   char ch;
   for(int i=0;i<n;++i)
   {
        cin>>ch;
        mp[ch]++;
   }
   string ans;

   for(int i=0;i<k;++i)
   {
        int cnt=0;
        if(mp.begin()->first!='a')
        {
            ans+='a';
            continue;
        }
        unordered_set<char>st;
        for(auto& p:mp)
        {
            if(p.second>0)
            {
                st.insert(p.first);
                p.second--;
                ++cnt;
            }
            if(cnt==(n/k))break;
        }
        for(char c='a';c<='z';++c)
        {
            if(!st.count(c))
            {
                ans+=c;
                break;
            }
        }
   }
   cout<<ans<<endl;
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
  int t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}