#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T,n;
  cin>>T;
  while(T--)
  {
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl;
        continue;
    }
    else 
    {
        n-=2;
        if(n%2&&n>1)cout<<1<<" ";
        for(int i=n;i>1;--i)
        {
            cout<<i<<" ";
        }
        if(n%2==0&&n>=2)cout<<1<<" ";
        cout<<n+1<<" "<<n+2;
        cout<<endl;
    }
  }
  return 0;
}