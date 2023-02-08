#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
struct ST
{
    static const int MAXN=1e6+10;
    vector<int>a;
    int n;
    vector<ll>tag,sum;
    inline int ls(int now){return now<<1;}
    inline int rs(int now){return now<<1|1;}
    ST(int num):n(num)
    {
        tag.assign(n<<2,0);
        sum.assign(n<<2,0);
    }
    inline void push_up(int now)
    {
        sum[now]=max(sum[ls(now)],sum[rs(now)]);
    }
    inline void f(int now,int l,int r,ll k)
    {
        tag[now]+=k;
        sum[now]+=k*(r-l+1);
    }
    inline void push_down(int now,int l,int r)
    {
        int mid=(l+r)>>1;
        f(ls(now),l,mid,tag[now]);
        f(rs(now),mid+1,r,tag[now]);
        tag[now]=0;
    }
    void init(vector<ll>arr)
    {
        a.assign(arr.begin(),arr.end());
        build(1,1,arr.size()-1);//1 index;
    }
    void build(int now,int l,int r)
    {
        tag[now]=0;
        if(l==r)
        {
            sum[now]=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(ls(now),l,mid);
        build(rs(now),mid+1,r);
        push_up(now);
    }
    void update(int now,int l,int r,int nl,int nr,ll k)//nl and nr are updated  range
    {
        if(nl<=l&&nr>=r)
        {
            sum[now]+=(r-l+1)*k;
            tag[now]+=k;
            return;
        }
        push_down(now,l,r);
        int mid=(l+r)>>1;
        if(nl<=mid)update(ls(now),l,mid,nl,nr,k);//mid表示原数组的中位（向下取整）
        if(nr>mid)update(rs(now),mid+1,r,nl,nr,k);
        push_up(now);
    }
    ll query(int ql,int qr,int now,int l,int r)
    {
        if(ql<=l&&qr>=r)
        {
            return sum[now];
        }
        ll ans=-1;
        int mid=(l+r)>>1;
        push_down(now,l,r);
        if(ql<=mid)
        {
            ans=max(ans,query(ql,qr,ls(now),l,mid));
        }
        if(qr>mid)
        {
            ans=max(ans,query(ql,qr,rs(now),mid+1,r));
        }
        return ans;
    } 
};
void solve()
{
  ll n,m;
  cin>>n>>m;
  vector<ll>a(m+1);
  for(int i=1;i<=m;++i)cin>>a[i];
  ST st(a.size());
  st.init(a);
  int q;
  cin>>q;
  while(q--)
  {
    int x1,y1,x2,y2,k;
    cin>>x1>>y1>>x2>>y2>>k;
    if(abs(x1-x2)%k || abs(y1-y2)%k)
    {
        cout<<"NO\n";
        continue;
    }
    if(y2<y1)
    {
        swap(x1,x2);
        swap(y1,y2);
    }
    ll end=((n-x1)/k)*k+x1;
    if(end>st.query(y1,y2,1,1,m))
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}