/*
卡特兰数的应用，笔记见pad
题目：入栈顺序为1...n ，求所有可能的出栈顺序的总数。
     怎么和卡特兰数关联起来呢？
     设x为最后一个出栈的
     设f[x]为所有可能性总数，则
     比x大的数有n-x个，可能性为f[n-x]
     比x小的数有x-1个，可能性为f[x-1]
     所以ans=f[0]*f[n-1]+....f[n-1]*f[0]
*/
#include <bits/stdc++.h>
using namespace std;
int solution()
{
    int n;
    cin>>n;
    using ll=long long;
    vector<ll>f(19,0);
    f[0]=1;
    f[1]=1;
    ll ans=0;
    for(int i=2;i<n;++i)
    {
        f[i]=f[i-1]*(4*i-2)/(i+1);
    }
    for(int i=0;i<n;++i)ans+=f[i]*f[n-1-i];
    cout<<ans<<endl;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solution();
  return 0;
}