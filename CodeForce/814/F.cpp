/*
    if gcd(k,n)==1， then we would always iterate all the number.
    if gcd(k,n)!=1 then we would iterate n/k number
    如果k是n的因子，那么从哪个地方开始选择都是一样的
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n,q;
  cin>>n>>q;
  vector<ll>a(n),b(n);
  vector sum(10,vector<ll>(n+1));
  int cnt=0;
  for(int i=0;i<n;++i)cin>>a[i];
  int x=n;
  for(int i=2;i<=x;++i)
  {
    if(x%i==0)
    {
        while(x%i==0)x/=i;
        b[++cnt]=n/i;
        for(int j=0;j<n;++j)
        {
            sum[cnt][j%b[cnt]]+=a[j];//选择第cnt个质因子的时候的解,对应分组
        }
    }
  }
  multiset<ll>st;
  for(int i=1;i<=cnt;++i)
  {
    for(int j=0;j<b[i];++j)
    {
        st.insert(sum[i][j]*b[i]);
    }
  }
  cout<<*st.rbegin()<<'\n';
  while(q--)
  {
    ll i,x;
    cin>>i>>x;
    i--;
    for(int j=1;j<=cnt;++j)
    {
        st.erase(st.find(sum[j][i%b[j]]*b[j]));
        sum[j][i%b[j]]+=x-a[i];
        st.insert(sum[j][i%b[j]]*b[j]);
    }
    a[i]=x;
    cout<<*st.rbegin()<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}