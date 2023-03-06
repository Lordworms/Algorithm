#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  string sa,sb;
  cin>>sa>>sb;
  vector<ll>a(n),b(n),c(n),d(n);//represent 1.the total number of situation 2. sa[i]>=sb[i] 3.sa[i]<=sb[i] 4. sa[i]==sb[i]
  // then the answer is A-B-C+D
  for(int i=0;i<n;++i)
  {
    if(sa[i]=='?'&&sb[i]=='?')
    {
        a[i]=100;
        b[i]=55;
        c[i]=55;
        d[i]=10;
    }
    else if(sa[i]=='?')
    {
        a[i]=10;
        b[i]=10-(sb[i]-'0');
        c[i]=sb[i]-'0'+1;
        d[i]=1;
    }
    else if(sb[i]=='?')
    {
        a[i]=10;
        c[i]=10-(sa[i]-'0');
        b[i]=sa[i]-'0'+1;
        d[i]=1;
    }
    else
    {
        a[i]=1;
        b[i]=(sa[i]>=sb[i]);
        c[i]=(sa[i]<=sb[i]);
        d[i]=(sa[i]==sb[i]);
    }
    if(i>0)
    {
        a[i]=(a[i]*a[i-1])%MOD;
        b[i]=(b[i]*b[i-1])%MOD;
        c[i]=(c[i]*c[i-1])%MOD;
        d[i]=(d[i]*d[i-1])%MOD;
    }
  }
  ll ans=a[n-1]-b[n-1]-c[n-1]+d[n-1];
  if(ans<0)ans+=MOD;
  cout<<ans<<'\n';
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