#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct LB
{
   vector<ll>p;
   int base;
   LB(int base=64)
   {
        p.resize(base);
        this->base=base;
   }   
   inline bool insert(ll x)
   {
        for(int i=base-1;i>=0;--i)
        {
            if(!(x>>i))continue;
            if(!p[i])
            {
                p[i]=x;
                break;
            }
            x^=p[i];
        }
        return x==0;
   }
   inline ll query(int x=0)
   {
        unsigned long long ans=0;
        for(int i=base-1;i>=0;--i)
        {
            ans=max(ans,ans^p[i]);
        }
        return ans;
   }
   void merge(const LB& aa)
   {
        for(int i=base-1;i>=0;--i)
        {
            if(aa.p[i])
            {
                insert(aa.p[i]);
            }
        }
   }
};
void solve()
{
  int n;cin>>n;
  vector<vector<int>>E(n+1),tree(n+1);
  vector<ll>a(n+1);
  vector<int>discover(n+1),terminal(n+1);
  vector<LB>lbs(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  for(int i=0;i<n-1;++i)
  {
    int x,y;
    cin>>x>>y;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  int cnt=0;
  vector<ll>order_id(10*n);
  function<void(int,int)>dfs_init=[&](int now,int fa)
  { 
    lbs[now].insert(a[now]);
    discover[now]=++cnt;
    order_id[cnt]=now;
    for(int v:E[now])
    {
        if(v==fa)continue;
        tree[now].push_back(v);
        dfs_init(v,now);
        lbs[now].merge(lbs[v]);
    }
    terminal[now]=cnt;
  };
  auto in_tree=[&](int sub_tree,int v)
  { 
    return discover[sub_tree]<=discover[v] && terminal[sub_tree]>=terminal[v];
  };
  auto get_child=[&](int s,int v)
  {
    int l=0,r=(int)tree[s].size()-1;
    int mid,node;
    while(l<=r)
    {
        mid=(l+r)>>1;
        node=tree[s][mid];
        if(terminal[node]<discover[v])
        {
            l=mid+1;
        }
        else if(discover[node]>discover[v])
        {
            r=mid-1;
        }
        else
        {
            return node;
        }
    }
  };
  dfs_init(1,-1);
  vector<LB>pre(n+1),suf(n+2);
  for(int i=1;i<=n;++i)
  {
    pre[i].insert(a[order_id[i]]);
    pre[i].merge(pre[i-1]);
  }
  for(int i=n;i>=1;--i)
  {
    suf[i].insert(a[order_id[i]]);
    suf[i].merge(suf[i+1]);
  }
  int q;cin>>q;
  while(q--)
  {
    int r,v;
    cin>>r>>v;
    if(r==v)
    {
        cout<<lbs[1].query()<<'\n';
    }
    else if(!in_tree(v,r))
    {
        cout<<lbs[v].query()<<'\n';
    }
    else
    {
        int node=get_child(v,r);//closest ansestor of r
        LB tmp;
        tmp.merge(pre[discover[node]-1]);
        tmp.merge(suf[terminal[node]+1]);
        cout<<tmp.query()<<'\n';
    }
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