#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int T;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>T;
  ll x,y,n;
  while(T--)
  {
    cin>>n>>x>>y;
    if(x>y)swap(x,y);
    if(x!=0||y==0)
    {
        cout<<-1<<endl;
        continue;
    }
    if(y==1)
    {
        cout<<1<<" ";
        for(int i=3;i<=n;++i)cout<<i<<" ";
        cout<<endl;
    }
    else if((n-1)%y)
    {
        cout<<-1<<endl;
    }
    else if(y==n-1)
    {
        for(int i=1;i<=n-1;++i)
        {
            cout<<2<<" ";
        }
        cout<<endl;
    }
    else
    {
        int s=2;
        for(int i=1;i<=(n-1);++i)
        {
            cout<<s<<" ";
            if(i%y==0)s+=y;
        }
        cout<<endl;
    }
  }
  return 0;
}