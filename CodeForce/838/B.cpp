#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
struct node
{
    int id,val;
};
void solve()
{
  vector<int>bd;
  int n;
  cin>>n;
  vector<node>arr(n);
  int minA=INT_MAX;
  for(int i=0;i<n;++i)
  {
    int x;
    cin>>x;
    arr[i]={i,x};
  }
  sort(arr.begin(),arr.end(),[&](node a,node b)
  {
    return a.val<b.val;
  });
  bd.push_back(arr[0].val);
  vector<pii>ans;
  for(int i=1;i<n;++i)
  {
    int id=lower_bound(bd.begin(),bd.end(),arr[i].val)-bd.begin();
    if(id>=bd.size())
    {
       ll up=bd.back();
       while(up<arr[i].val)
       {
        up*=2;
       }
       bd.push_back(up);
       if(up>arr[i].val)ans.push_back({arr[i].id+1,up-arr[i].val});
    }
    else
    {
        ans.push_back({arr[i].id+1,bd[id]-arr[i].val});
    }
  }
  cout<<ans.size()<<'\n';
  sort(ans.begin(),ans.end(),[&](pii a,pii b){
    return a.first<b.first;
  });
  for(auto pi:ans)
  {
    cout<<pi.first<<' '<<pi.second<<'\n';
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
