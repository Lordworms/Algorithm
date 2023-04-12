#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
#define lowbit(x) (x&-x)
vector<int>pos,a;
vector<int>c,in,out;
struct ST{
    vector<ll>tree;
    vector<ll>tag;
    ST(int n){
        tree.resize(n<<2);
        tag.resize(n<<2);
    }
    inline void push_down(int c){
        if(tag[c]!=0){
            tag[c<<1]=tag[c<<1|1]=tag[c];
            tree[c<<1]=tree[c<<1|1]=tag[c];
            tag[c]=0;
        }   
    }
    inline void push_up(ll c){
        tree[c]=tree[c<<1]|tree[c<<1|1];
    }
    void build(int l,int r,int c){
        if(l==r){
            tree[c]=1ll<<(a[pos[l]]);//纯低能错误
            return;
        }
        int mid=(l+r)>>1;
        build(l,mid,c<<1);
        build(mid+1,r,c<<1|1);
        push_up(c);
    }
    void update(int l,int r,int c,int nl,int nr,ll v){
        if(nl<=l&&nr>=r){
            tree[c]=(1ll<<v);
            tag[c]=(1ll<<v);
            return;
        }
        push_down(c);
        int mid=(l+r)>>1;
        if(nl<=mid)update(l,mid,c<<1,nl,nr,v);
        if(nr>mid)update(mid+1,r,c<<1|1,nl,nr,v);
        push_up(c);
    }
    ll query(int l,int r,int ql,int qr,int c){
        if(ql<=l&&qr>=r){
            return tree[c];
        }
        push_down(c);
        ll res=0;
        int mid=(l+r)>>1;
        if(ql<=mid){
            res|=query(l,mid,ql,qr,c<<1);
        }
        if(qr>mid){
            res|=query(mid+1,r,ql,qr,c<<1|1);
        }
        return res;
    }
};
void solve(){
  int n,q;
  cin>>n>>q;
  int cnt=0;
  a.resize(n+1);
  in.resize(n<<2);
  out.resize(n<<2);
  pos.resize(n+1);
  vector<vector<int>>E(n+1);
  for(int i=1;i<=n;++i){
    cin>>a[i];
  }
  for(int i=0;i<n-1;++i){
    int u,v;
    cin>>u>>v;
    E[v].push_back(u);
    E[u].push_back(v);
  }
  function<void(int,int)>dfs=[&](int x,int f){
    in[x]=++cnt;
    pos[cnt]=x;
    for(int v:E[x]){
        if(v==f)continue;
        dfs(v,x);
    }
    out[x]=cnt;
  };
  dfs(1,0);
  ST seg(cnt);
  seg.build(1,cnt,1);
  while(q--){
    int type;
    cin>>type;
    if(type==1){//change
        int v,c;
        cin>>v>>c;
        seg.update(1,n,1,in[v],out[v],c);
    }else{//get
        int k;
        cin>>k;
        ll res=seg.query(1,n,in[k],out[k],1);
        int ans=0;
        while(res){
            res-=lowbit(res);
            ans++;
        }
        cout<<ans<<'\n';
    }
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}