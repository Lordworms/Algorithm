#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=2e5+100;
struct ST
{
    static const int MAXN=2e5+10;
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
        sum[now]=sum[ls(now)]+sum[rs(now)];
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
    void init(vector<int>arr)
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
            sum[now]+=1ll*(r-l+1)*k;
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
        ll ans=0;
        int mid=(l+r)>>1;
        push_down(now,l,r);
        if(ql<=mid)
        {
            ans+=query(ql,qr,ls(now),l,mid);
        }
        if(qr>mid)
        {
            ans+=query(ql,qr,rs(now),mid+1,r);
        }
        return ans;
    } 
    int query0(int now,int l,int r,int x)//找右边第一个0，用于1+1
    {
        if(r<x||sum[now]==r-l+1)
        {
            return -1;
        }
        if(l==r&&sum[now]==0)
        {
            return l;
        }
        push_down(now,l,r);
        int mid=(l+r)>>1;
        int res=query0(now<<1,l,mid,x);
        if(~res)return res;
        return query0(now<<1|1,mid+1,r,x);
    }
    int query1(int now,int l,int r,int x)//找右边第一个1，用于0-1
    {
       if(r<x||sum[now]==0)
        {
            return -1;
        }
        if(l==r)
        {
            return l;
        }
        push_down(now,l,r);
        int mid=(l+r)>>1;
        int res=query1(now<<1,l,mid,x);
        if(~res)return res;
        return query1(now<<1|1,mid+1,r,x);        
    }
    int find(int l,int r,int now)
    {
        if(l==r)return l;
        push_down(now,l,r);
        int mid=(l+r)>>1;
        if(sum[now<<1|1])return find(mid+1,r,now<<1|1);
        return find(l,mid,now<<1);
    }
};
void solve()
{
  int n,q;
  cin>>n>>q;
  vector<int>a(n+1);
  vector<int>cnt(MAXN);
  for(int i=1;i<=n;++i)
  {
    cin>>a[i];
    cnt[a[i]]++;
  }
  for(int i=1;i<MAXN-1;++i)
  {
    cnt[i+1]+=(cnt[i]/2);
    cnt[i]%=2;
  }
  ST st(MAXN);
  st.init(cnt);
  while(q--)
  {
    int k,x;
    cin>>k>>x;
    if(st.query(a[k],a[k],1,1,MAXN-1)==1)//minus
    {
        st.update(1,1,MAXN-1,a[k],a[k],-1);
    }
    else
    {
        int r=st.query1(1,1,MAXN-1,a[k]);
        st.update(1,1,MAXN-1,a[k],r-1,1);
        st.update(1,1,MAXN-1,r,r,-1);
    }
    a[k]=x;
    if(st.query(a[k],a[k],1,1,MAXN-1)==0)
    {
        st.update(1,1,MAXN-1,a[k],a[k],1);
    }
    else
    {   
        int r=st.query0(1,1,MAXN-1,a[k]);
        st.update(1,1,MAXN-1,a[k],r-1,-1);
        st.update(1,1,MAXN-1,r,r,1);
    }
    cout<<st.find(1,MAXN-1,1)<<'\n';
  }
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}