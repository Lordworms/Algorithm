#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
void solve()
{   
    int n,k;
    cin>>n>>k;
    int a1,b1;
    cin>>a1>>b1;
    int des=k-b1;
    vector<pii>arr(n-1);
    for(int i=0;i<n-1;++i)cin>>arr[i].first>>arr[i].second;
    sort(arr.begin(),arr.end(),[](pii a,pii b){
        return a.first+a.second>b.first+b.second;
    });
    if(k>a1+b1)
    {
        cout<<"NO"<<'\n';
        return;
    }
    if(k<=a1)
    {
        cout<<"YES"<<'\n';
        return;
    }
    for(int i=0;i<n-1;++i)
    {
        if(des>arr[i].first+arr[i].second)break;
        if(i!=n-2&&arr[i+1].first+arr[i+1].second>=des)
        {
            cout<<"YES"<<'\n';
            return;
        }
        if(arr[i].first>=des)
        {
            cout<<"YES"<<'\n';
            return;
        }
        des-=arr[i].second;
    }
    cout<<"NO"<<'\n';
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