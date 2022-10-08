#include <bits/stdc++.h>
using namespace std;
int t;
int n;
using ll=long long;
void solve()
{
    cin>>n;
    vector<int>type(n);
    vector<ll>a,b;
    for(int i=0;i<n;++i)cin>>type[i];
    ll x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        if(type[i]==1)
        {
            b.push_back(x);
        }
        else 
        {
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end(),greater<ll>());
    sort(b.begin(),b.end(),greater<ll>());
    ll ans=0;
    if(a.size()>b.size())swap(a,b);
    if(a.size()==b.size())
    {
        ans=accumulate(a.begin(),a.end()-1,0ll)+accumulate(b.begin(),b.end()-1,0ll)+max(a.back(),b.back());
    }
    else
    {
        ans=accumulate(a.begin(),a.end(),0ll)+accumulate(b.begin(),b.begin()+a.size(),0ll);
    }
    ans+=accumulate(a.begin(),a.end(),0ll);//注意accumulate的ll
    ans+=accumulate(b.begin(),b.end(),0ll);
    cout<<ans<<endl;
    return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}