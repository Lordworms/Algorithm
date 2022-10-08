/*
    1. just one vertex in (0,n+1) which is isolated
    2. the graph contains no loop
    3. for every vertex in G, at most one child is not a leaf
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    vector<int>b(n);
    int k=0;
    vector<vector<int>>E(n+2);
    for(int i=0;i<n;++i){
        cin>>b[i];
        if(b[i]>i)k=max(k,i+1);
        else k=max(k,b[i]);
        E[b[i]].push_back(i+1);
    }
    int cnt=0;
    int x=0;
    if(E[x].empty())x=n+1;
    vector<int>ans;
    while(cnt<n)
    {
        cnt+=E[x].size();
        for(auto& k:E[x])
        {
            if(!E[k].empty())
            {
                swap(k,E[x].back());//先合并叶子结点，不然会有冲突
            }
        }
        ans.insert(ans.end(),E[x].begin(),E[x].end());
        x=E[x].back();
    }
    cout<<k<<endl;
    for(auto& a:ans)cout<<a<<" ";
    cout<<endl;
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