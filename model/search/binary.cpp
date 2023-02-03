#include <bits/stdc++.h>
using namespace std;
vector<int>a={1,1,2,3,4,5,5,5,6,7,8,9,9,9,10};
int binary_search_1(int l,int r,int tar)//return the last element less than 5
{
  int m;
  while(l<=r)
  {
    m=(l+r)>>1;
    if(a[m]>=tar)
    {
      r=m-1;
    }
    else
    {
      l=m+1;
    }
  }
  return r;
}
int binary_search_2(int l,int r,int tar)//return the last element less or equal than 5
{
   int m;
   while(l<=r)
   {
      m=(l+r)>>1;
      if(a[m]>tar)
      {
        r=m-1;
      }
      else
      {
        l=m+1;
      }
   }
   return r;
}
int binary_search_3(int l,int r,int tar)//return the first element greater  than 5
{
  int m;
  while(l<=r)
  {
    m=(l+r)>>1;
    if(a[m]<=tar)
    {
      l=m+1;
    }
    else
    {
      r=m-1;
    }
  }
  return l;
}
int binary_search_4(int l,int r,int tar)//return the first element greater or equal than 5
{
  int m;
  while(l<=r)
  {
    m=(l+r)>>1;
    if(a[m]<tar)
    {
      l=m+1;
    }
    else
    {
      r=m-1;
    }
  }
  return l;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n=a.size();
  cout<<"the last element less than 5 is"<<binary_search_1(0,n,5)<<' '<<a[binary_search_1(0,n,5)]<<'\n';
  cout<<"the last element less or equal than 5 is"<<binary_search_2(0,n,5)<<' '<<a[binary_search_2(0,n,5)]<<'\n';
  cout<<"the first element greater than 5 is"<<binary_search_3(0,n,5)<<' '<<a[binary_search_3(0,n,5)]<<'\n';
  cout<<"the first element greater or equal than 5 is"<<binary_search_4(0,n,5)<<' '<<a[binary_search_4(0,n,5)]<<'\n';
  return 0;
}