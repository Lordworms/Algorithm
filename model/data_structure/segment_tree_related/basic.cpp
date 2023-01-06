#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//with 1 index
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
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int n,m;
  cin>>n>>m;
  ST st(n);
  vector<int>arr(n+1);
  for(int i=1;i<=n;++i)cin>>arr[i];
  st.init(arr);
  for(int i=0;i<m;++i)
  {
    int x,l,r;
    ll k;
    cin>>x;
    switch (x)
    {
        case 1:
        {
            cin>>l>>r>>k;
            st.update(1,1,n,l,r,k);   
        }
        break;
        case 2:
        {
            cin>>l>>r;
            cout<<st.query(l,r,1,1,n)<<'\n';
        }
        break;
    default:
        break;
    }
  }
  return 0;
}