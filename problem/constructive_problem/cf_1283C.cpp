#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
    unordered_set<int>send,received;
    int n;cin>>n;
    vector<int>f(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>f[i];
        if(f[i])send.insert(i);
        if(f[i]&&!received.count(f[i]))received.insert(f[i]);
    }
    vector<int>unsend,unrecieved;
    for(int i=1;i<=n;++i)
    {
        if(!send.count(i))
        {
            unsend.push_back(i);
        }
        if(!received.count(i))
        {
            unrecieved.push_back(i);
        }
    }
    sort(unsend.begin(),unsend.end());
    sort(unrecieved.begin(),unrecieved.end(),greater<int>());
    for(int i=0;i<unsend.size();++i)
    {
        if(f[unsend[i]])continue;
        if(unsend[i]!=unrecieved[i])
        {
            f[unsend[i]]=unrecieved[i];
        }
        else 
        {
            bool changed=false;
            if(i)
            {
                for(int j=0;j<i;++j)
                {
                    if(unsend[j]!=unrecieved[i])
                    {
                        f[unsend[i]]=f[unsend[j]];
                        changed=true;
                        f[unsend[j]]=unrecieved[i];
                        break;
                    }
                }
            }
            if(!changed&&i<unsend.size()-1)
            {
                for(int j=unsend.size()-1;j>i;--j)
                {
                    if(unsend[j]!=unrecieved[i])
                    {
                        f[unsend[i]]=unrecieved[j];
                        f[unsend[j]]=unrecieved[i];
                        break;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<f[i]<<" \n"[i==n];
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