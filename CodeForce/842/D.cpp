/*
    置换环问题
    结论：冒泡排序的最少交换次数为逆序对的对数
    https://zhuanlan.zhihu.com/p/596949353
    1. 把i和p[i]进行连接，会得到k个环，数组是有序的当且仅当k==n
    2. 交换同一个环中的两个数会导致环被拆分成两个环，交换不同环中的两个数导致环被合并成一个环
    3. 有num个环，进行n-num次操作可以把环变的有序
    4. 如果环中有相邻的两个元素，那么我们不用交换他们
    5. n-num-1 or n-num+1 就是最后的答案
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  vector<int>a(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  vector<bool>vis(n+1,false);
  map<int,bool>ring;
  bool flag=false;
  function<void(int)>dfs=[&](int now)
  {
    if(vis[now])return;
    vis[now]=true;
    ring[now]=true;
    if(ring[now-1]||ring[now+1])flag=true;
    dfs(a[now]);
  };
  int cur=0;

  for(int i=1;i<=n;++i)
  {
    if(!vis[i])
    {
        ring.clear();
        ++cur;
        dfs(i);
    }
  }
  cout<<(flag?n-cur-1:n-cur+1)<<'\n';
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