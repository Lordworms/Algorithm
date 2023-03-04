#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;++i)
  {
    char c;
    cin>>c;
    a[i]=c-'0';
  }
  vector<int>ans;
  if(a[0]==9)
  {
    ans.assign(n+1,1);
    for(int i=n;i>0;--i)
    {
        if(ans[i]>=a[i-1])
        {
            ans[i]-=a[i-1];
        }
        else
        {
           int k=i-1;
           while(ans[k]==0)
           {
                ans[k]=9;
                --k;
           }
           ans[k]--;
           (ans[i]-=a[i-1])+=10;
        }
    }
  }
  else
  {
    ans.assign(n,9);
    for(int i=n-1;i>=0;--i)
    {
        if(ans[i]>=a[i])
        {
            ans[i]-=a[i];
        }
        else
        {
           int k=i-1;
           while(ans[k]==0)
           {
                ans[k]=9;
                --k;
           }
           ans[k]--;
           (ans[i]-=a[i])+=10;
        }
    }
  }
  int st=0;
  while(ans[st]==0)st++;
  for(int i=st;i<ans.size();++i)
  {
    cout<<ans[i];
  }
  cout<<'\n';
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