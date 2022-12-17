/*
1. if the xor of [l,r] is not equal to zero, then the answer is -1
2. if the whole part is zero, just output zero
3. if the length of [l,r] is odd, then we could just make one move to make it
4. if the length of [l,r] is even, and a[l] or a[r] is equal to 0, then 
    这题真的有点吊，吗的注意两个表的使用以及区间判0的使用，牛的

*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,q;
  cin>>n>>q;
  vector<int>arr(n+1),xo(n+1);
  vector<int>sign(n+1);
  vector<int>bef(n+1);
  unordered_map<ll,ll>odd,even;
  int id=0;
  for(int i=1;i<=n;++i)
  {
    cin>>arr[i];
    if(i==1)xo[i]=arr[i];
    else xo[i]=xo[i-1]^arr[i];
    if(arr[i]!=0)id=i;
    sign[i]=id;
    if(i%2)
    {
        odd[xo[i]]=i;
        bef[i]=even[xo[i]];
    }
    else
    {
        even[xo[i]]=i;
        bef[i]=odd[xo[i]];
    }
  }
  auto query=[&](int l,int r)
  {
    if((xo[r]^xo[l-1])!=0)return -1;
    if(sign[r]<l)return 0;
    if((r-l+1)&1)return 1;
    if(arr[l]==0||arr[r]==0)return 1;
    if(bef[r]>l)return 2;
    return -1;
  };
  for(int i=0;i<q;++i)
  {
    int l,r;
    cin>>l>>r;
    cout<<query(l,r)<<'\n';
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
  solve();
  return 0;
}