#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,m;
  cin>>n;
  vector<int>a(n+1);
  vector<int>left(n+1),right(n+1),now_right(n+1);
  vector<ll>s1(n+1),s2(n+1);
  for(int i=1;i<=n;++i)cin>>a[i];
  //pre caculate the most left pos that i could reach, the most right pos that i could reach and the most right pos that i could reach if i could jump a invalid position
  for(int l=1,r1=1,r2=1;l<=n;++l)
  {
    while(r1<=n&&a[r1]>=r1-l+1)
    {
      left[r1]=l;
      ++r1;
    }
    right[l]=r1-1;
    r2=max(r2,min(r1+1,n+1));
    while(r2<=n&&a[r2]>=r2-l+1)++r2;
    now_right[l]=r2-1;//watch out for the -1!!!!
  }
  //calculate the sum for normal right and modified right
  for(int i=1;i<=n;++i)
  {
    s1[i]=s1[i-1]+(right[i]-i+1);
    s2[i]=s2[i-1]+(now_right[i]-i+1);
  }
  cin>>m;
  int x,p;
  ll now=s1.back();
  for(int i=1;i<=m;++i)
  {
    cin>>p>>x;
    if(a[p]==x)//did not modify anything, then we just print the original ans
    {
      cout<<now<<'\n';
      continue;
    }
    else if(a[p]<x)//now x is greater than a[p], which means the ans is increasing
    {
      int now_left=max((int)(lower_bound(right.begin()+1,right.end(),p-1)-right.begin()),p-x+1);//p-x+1 makes sure that it could go over it
      ll oldSum=s1[left[p]-1]-s1[now_left-1];
      ll newSum=s2[left[p]-1]-s2[now_left-1];
      cout<<now-oldSum+newSum<<'\n';
    }
    else//now x is smaller than a[p], which means the ans is decreasing
    {
      int now_left=max(left[p],p-x+1);//make sure now_left could reach p
      ll cut=s1[now_left-1]-s1[left[p]-1];
      ll remain=(ll)(p-now_left)*(now_left-left[p])+(ll)(now_left-left[p])*(now_left-left[p]+1)/2;
      //ll remain=
      cout<<now-cut+remain<<'\n';
    }
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
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}