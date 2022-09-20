#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e2+10;
int n,k,T;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>T;
  while(T--)
  {
    cin>>n>>k;
    vector<long long>arr(k+1,0);
    long long x;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        arr[i%k]=max(arr[i%k],x);
    }
    long long ans=0;
    cout<<accumulate(arr.begin(),arr.end(),ans)<<endl;
  }
  return 0;
}