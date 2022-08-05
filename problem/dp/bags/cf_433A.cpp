/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=20010;
int v[MAXN];
int f[MAXN];
int n;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int sum=0;
  int n;
  cin>>n;
  for(int i=0;i<n;++i)cin>>v[i],sum+=v[i];
  if(sum%2){cout<<"NO"<<endl;return 0;}
  for(int i=0;i<n;++i)
  {
    for(int j=sum;j>=v[i];--j)
    {
        if(j>1)f[j]=max(f[j-v[i]]+v[i],f[j]);
    }
  }
  cout<<(f[sum/2]==sum/2?("YES"):("NO"))<<endl;
  return 0;
}