#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T,n;
  cin>>T;
  while(T--)
  {
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i)cin>>arr[i];
    vector<vector<int>>ans;
    if(n>1&&arr[0]%2==arr[n-1]%2)
    {
        ans.push_back({0,n-1});
        arr[0]=arr[n-1];
    }
    for(int i=1;i<n;++i)
    {
        if(arr[i]%2!=arr[0]%2)
        {
            ans.push_back({0,i});
            arr[i]=arr[0];
        }
    }
    for(int i=n-2;i>=0;--i)
    {
        if(arr[i]!=arr[n-1])
        {
            ans.push_back({i,n-1});
            arr[i]=arr[n-1];
        }
    }
    cout<<ans.size()<<endl;
    for(auto s:ans)
    {
        cout<<s[0]+1<<" "<<s[1]+1<<endl;
    }
  }
  return 0;
}