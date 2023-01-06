#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
const ld eps=1e-9;
void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>p(n),q(n);
    for(int i=0;i<n;++i)cin>>p[i];
    for(int i=0;i<n;++i)cin>>q[i];
    ld sx,sy,tx,ty;
    sx=tx=a,sy=ty=b;
    if(a==0&&b==0)
    {
        for(int i=0;i<n;++i)
        {
            cout<<0<<'\n';
        }
        return;
    }
    multiset<pair<ld,ld>>st;//sort by k (decrease order)
    for(int i=0;i<n;++i)
    {
        ld pi=p[i],qi=q[i];
        sx-=pi,tx+=pi,sy+=qi,ty-=qi;
        st.insert({qi/pi,pi+pi});//using the -k and the length on x-dir to represent a segment
        //cut the negative part
        while(sx<-eps)
        {
            auto it=st.begin();//using the biggest k
            auto[slope,xlen]=*it;
            st.erase(it);
            if(sx+xlen>0)
            {
                ld d=sx+xlen;
                xlen-=d;
                st.insert({slope,d});
            }
            sx+=xlen,sy-=xlen*slope;//move to next line
        }
        while(ty<-eps)
        {
            auto it=--st.end();//smallest k
            auto [slope,xlen]=*it;
            st.erase(it);
            if(ty+slope*xlen>0)
            {
                ld d=ty/slope+xlen;
                xlen-=d;
                st.insert({slope,d});
            }
            tx-=xlen,ty+=slope*xlen;
        }
        typedef numeric_limits< double > dbl;//精度控制
        cout.precision(dbl::digits10);
        cout<<tx<<'\n';
    }
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