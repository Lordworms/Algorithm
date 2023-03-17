#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=100000+10;
const double esp=1e-6;
const double PI=3.1415926;
struct node{
    ll v;
    int id;
};
ll tree[MAXN<<4];
vector<node>arr;
void build(int l,int r,int c){
    if(l==r){
        tree[c]=0;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,c<<1);
    build(m+1,r,c<<1|1);
}
ll query(int l,int r,int ql,int qr,int c){
    if(ql<=l&&r<=qr){
        return tree[c];
    }
    int m=(l+r)>>1;
    ll ans=0;
    if(ql<=m){
        ans=max(ans,query(l,m,ql,qr,c<<1));
    }
    if(qr>m){
        ans=max(ans,query(m+1,r,ql,qr,c<<1|1));
    }
    return ans;
}
void update(int l,int r,int c,int id,ll v){
    if(l==r){
        tree[c]=v;
        return;
    }
    int m=(l+r)>>1;
    if(id<=m)update(l,m,c<<1,id,v);
    else if(id>m)update(m+1,r,c<<1|1,id,v);
    tree[c]=max(tree[c<<1],tree[c<<1|1]);
}
void solve(){
  int n;cin>>n;
  arr.resize(n+1);
  vector<ll>dp(n+1);//means the answer of cake end with i
  dp[0]=1;
  for(int i=1;i<=n;++i){
    ll r,h;cin>>r>>h;
    arr[i].v=r*r*h;
    arr[i].id=i;
  }
  sort(arr.begin()+1,arr.end(),[&](node a,node b){
    if(fabs(a.v-b.v)<esp)return a.id>b.id;
    return a.v<b.v;
  });
  double ans=0;
  build(1,n,1);
  for(int i=1;i<=n;++i){
    int id=arr[i].id;
    ll res=query(1,n,1,id,1)+arr[i].v;
    update(1,n,1,id,res);
    ans=max(ans,res*1.0);
  }
  ans*=PI;
  cout.precision(9);
  cout<<ans<<'\n';
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