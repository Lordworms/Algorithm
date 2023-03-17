#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct SegTree{
    const int N=1e5+10;
    struct node{
        int l,r;
        ll sum,add;
    };
    vector<node>tr;
    vector<int>w;
    SegTree(int n){
        tr.resize(N<<2);
        w.resize(n+1);
    }
    void push_up(int now){
        tr[now].sum=tr[now<<1].sum+tr[now<<1|1].sum;
    }
    void push_down(int now){
        auto & l=tr[now<<1],&r=tr[now<<1|1];
        auto &add=tr[now].add;
        if(add){
            l.sum+=(l.r-l.l+1)*add;
            r.sum+=(r.r-r.l+1)*add;
            l.add+=add;
            r.add+=add;
            add=0;
        }
    }
    void build(int now,int l,int r){
        if(l==r){
            tr[now]={l,r,w[l],0};
            return;
        }
        tr[now]={l,r,0,0};
        int mid=(l+r)>>1;
        build(now<<1,l,mid);
        build(now<<1|1,mid+1,r);
    }
    void modify(int now,int l,int r,int v){
        if(tr[now].l>=l&&tr[now].r<=r){
            tr[now].sum+=(tr[now].r-tr[now].l+1)*v;
            tr[now].add+=v;
            return;
        }
        push_down(now);
        int mid=(tr[now].l+tr[now].r)>>1;
        if(l<=mid){
            modify(now<<1,l,mid,v);
        }
        if(r>mid){
            modify(now<<1|1,mid+1,r,v);
        }
        push_up(now);
    }
    ll query(int now,int x){
        if(tr[now].l==x||tr[now].r==x)return tr[now].sum;
        else{
            push_down(now);
            int mid=(tr[now].l+tr[now].r)>>1;
            if(x<=mid){
                return query(now<<1,x);
            }
            else{
                return query(now<<1|1,x);
            }
        }
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}