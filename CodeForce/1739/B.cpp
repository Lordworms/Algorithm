#include <bits/stdc++.h>
using namespace std;
int n,t;
void solve()
{
    cin>>n;
    vector<int>d(n);
    for(int i=0;i<n;++i)cin>>d[i];
    vector<int>a(n);
    a[0]=d[0];
    for(int i=1;i<n;++i)
    {
        if(d[i]>0&&a[i-1]>=d[i])
        {
            cout<<-1<<endl;
            return;
        }
        a[i]=a[i-1]+d[i];
    }
    for(int i=0;i<n;++i){
      cout<<a[i];
      if(i!=n-1)cout<<" ";
      else cout<<"\n";
    }
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