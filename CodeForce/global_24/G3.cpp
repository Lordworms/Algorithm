#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int query(int a,int b,int k)
{
    cout<<"? "<<a<<' '<<b<<' '<<k<<'\n';
    cout.flush();
    int ans;
    cin>>ans;
    return ans;
}
void report(int x)
{
    cout<<"! "<<x<<'\n';
    cout.flush();
}
int flag=-1;
void dfs(int l,int r,int l1,int l2,int r1,int r2)// l1: C(1,r) l2:C(1,r-1) r2:C(r+1,n) r1=C(l,n)
{
    if(l==r)
    {
        report(l);
        return;
    }
    if(l+1==r)
    {
        if(r1==r2+1)//check [r+1,n]
        {
            if(query(r,n,2)==r2+1)report(r);
            else report(l);
        }
        else if(l1==l2+1)
        {
            if(query(1,l,2)==l2+1)report(l);
            else report(r);
        }
        else
        {
            if(l>1)
            {
                if(query(1,l,n)==2)report(r);
                else report(l);
            }
            else
            {
                if(query(r,n,n)==2)report(l);
                else report(r);
            }
        }
    }
    int mid=(l+r)>>1;
    int L=query(1,mid,2),R=query(mid+1,n,2);
    if(2*L-mid>2*R-(n-mid))
    {
        dfs(l,mid,L,l2,r1,R);
    }
    else if(2*L-mid<2*R-(n-mid))
    {
        dfs(mid+1,r,l1,L,R,r2);
    }
    else
    {
        if(~flag)//flag<0
        {
            if(flag)
            {
                dfs(l,mid,L,l2,r1,R);
            }
            else 
            {
                dfs(mid+1,r,l1,L,R,r2);
            }
        }
        if(query(1,mid,n)==2)
        {
            flag=0;
            dfs(mid+1,r,l1,L,R,r2);
        }
        else
        {
            flag=1;
            dfs(l,mid,L,l2,r1,R);
        }
    }

}
void solve()
{
    cin>>n;
    dfs(1,n,n/2+1,0,n/2+1,0);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  solve();
  return 0;
}