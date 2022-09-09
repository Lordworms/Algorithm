#include <bits/stdc++.h>
using namespace std;
const int MAXN=4*1e5+10;
int a[MAXN],b[MAXN];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T,n;
  cin>>T;
  auto getC=[&](int v){
    return std::to_string(v).size();
  };
  priority_queue<int>qa,qb;
  while(T--)
  {
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i],qa.push(a[i]);
    for(int i=0;i<n;++i)cin>>b[i],qb.push(b[i]);
    int ans=0;
    while(!qa.empty())
    {
        int x=qa.top(),y=qb.top();
        if(x>y)
        {
            qa.pop();
            qa.push(getC(x));
            ++ans;
        }
        else if(y>x)
        {
            qb.pop();
            qb.push(getC(y));
            ++ans;
        }
        else
        {
            qa.pop(),qb.pop();
        }
    }
    cout<<ans<<endl;
  }
  return 0;
}