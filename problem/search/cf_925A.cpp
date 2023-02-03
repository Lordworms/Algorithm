#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,m,cs,ce,v;
  cin>>n>>m>>cs>>ce>>v;
  vector<int>css(cs);
  vector<int>cee(ce);
  for(int i=0;i<cs;++i)cin>>css[i];
  for(int i=0;i<ce;++i)cin>>cee[i];
  int q;
  cin>>q;
  auto search_left=[&](int x,vector<int>& a)
  {
    int l=0,r=a.size()-1,m;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(m<0)return (int)1e9;
        if(a[m]>x)
        {
            r=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    if(r<0)return (int)1e9;
    return a[r];
  };
  auto search_right=[&](int x,vector<int>& a)
  {
    int l=0,r=a.size()-1,m;
    while(l<=r)
    {
        m=(l+r)>>1;
        if(m>=a.size())return (int)1e9;
        if(a[m]<x)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        } 
    }
    if(l>=a.size())return (int)1e9;
    return a[l];
  };
  auto calc=[&](int x1,int x2)
  {
    int dis=abs(x1-x2);
    return dis/v+(dis%v!=0);
  };
  while(q--)
  {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
    {
        cout<<abs(y1-y2)<<'\n';
    }
    else
    {
        ll sll=search_left(y1,css);
        ll sl=abs(sll-y1)+abs(x1-x2)+abs(sll-y2);
        ll srr=search_right(y1,css);
        ll sr=abs(srr-y1)+abs(x1-x2)+abs(srr-y2);
        ll ell=search_left(y1,cee);
        ll el=abs(ell-y1)+calc(x1,x2)+abs(ell-y2);
        ll err=search_right(y1,cee);
        ll er=abs(err-y1)+calc(x1,x2)+abs(err-y2);
        cout<<std::min({sl,sr,el,er})<<'\n';
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