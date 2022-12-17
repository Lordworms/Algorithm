#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAX=1000100;
class ST{
public:
    vector<ll> segs;
    ll size=0;                       
    ll ID=MAX;
 
    ST(ll sz) {
        segs.assign(2*sz,ID);
        size=sz;  
    }   
   
    ll comb(ll a,ll b) {
        return min(a,b);  
    }
 
    void upd(ll idx, ll val) {
        segs[idx+=size]=val;
        for(idx/=2;idx;idx/=2){
            segs[idx]=comb(segs[2*idx],segs[2*idx+1]);
        }
    }
 
    ll query(ll l,ll r) {
        ll lans=ID,rans=ID;
        for(l+=size,r+=size+1;l<r;l/=2,r/=2) {
            if(l&1) {
                lans=comb(lans,segs[l++]);
            }
            if(r&1){
                rans=comb(segs[--r],rans);
            }
        }
        return comb(lans,rans);
    }
};
struct FenwickTree{
    vector<ll> bit; 
    ll n;
    FenwickTree(ll n){
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<ll> a):FenwickTree(a.size()){
        ll x=a.size();
        for(size_t i=0;i<x;i++)
            add(i,a[i]);
    }
    ll sum(ll r) {
        ll ret=0;
        for(;r>=0;r=(r&(r+1))-1)
            ret+=bit[r];
        return ret;
    }
    ll sum(ll l,ll r) {
        if(l>r)
            return 0;
        return sum(r)-sum(l-1);
    }
    void add(ll idx,ll delta) {
        for(;idx<n;idx=idx|(idx+1))
            bit[idx]+=delta;
    }
};
FenwickTree freq(MAX);  
ST segtree(MAX);
int n,k;
vector<ll> dp(MAX,0);
ll work(vector<ll>arr)  
{
    ll now=0;
    for(ll i=n-1;i>=0;i--){  
        ll j=segtree.query(arr[i]+1,arr[i]+k);
        if(j<n){
            dp[i]=dp[j]+freq.sum(arr[i]+1,arr[j]);
        }
        else{
            dp[i]=0;
        }
        now+=dp[i];
        segtree.upd(arr[i],i);
        freq.add(arr[i],1);
    }  
    for(auto it:arr){  
        segtree.upd(it,MAX);  
        freq.add(it,-1); 
    }
    return now;
};
void solve()
{
  cin>>n>>k;
  vector<ll>arr(n);
  map<ll,ll>mp;
  ll ans=0;
  for(int i=0;i<n;++i)
  {
    cin>>arr[i];
    mp[arr[i]]++;
    ans+=mp[arr[i]];
  }
  ans+=work(arr);
  reverse(arr.begin(),arr.end());
  ans+=work(arr);
  cout<<ans<<'\n';
  return;
}
signed main()
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