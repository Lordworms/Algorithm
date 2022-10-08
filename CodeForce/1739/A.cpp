#include <bits/stdc++.h>
using namespace std;
int m,n;
void solve()
{
    cin>>n>>m;
    if(n==1||m==1)
    {
        cout<<1<<" "<<1<<endl;
        return;
    }
    if(n==2)
    {
       if(m==2)
       {
        cout<<1<<" "<<1<<endl;
        return;
       }
       else if(m==3)
       {
        cout<<1<<" "<<2<<endl;
        return;
       }
       else {cout<<1<<" "<<1<<endl;return;}
    }
    if(m==2)
    {
        if(n==2)
       {
        cout<<1<<" "<<1<<endl;
        return;
       }
       else if(n==3)
       {
        cout<<2<<" "<<1<<endl;
        return;
       }
       else {cout<<1<<" "<<1<<endl;return;}
    }
    if(m==3&&n==3){cout<<2<<" "<<2<<endl;return;}
    cout<<1<<" "<<1<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  
  while(t--)
  {
    solve();
  }
  return 0;
}