/*
size of n is 1e5 so that we need to reduce our search domains
we have total 82 questions
There are two problems
 1. how can we determine whether a answer is correct or not?
 we can ask two consecutive problem to determine whether a question is correct or not
 a.
  ask(Set A) > No
  ask(Set A) > No
 if it is situation a, then the target is not in the Set A. OtherWise, it is in
 2. how can we reduce our search domain?
   split A into four parts A1 A2 A3 A4
   ask(A1|A2)
   ask(A1|A3)
  if the answer is both Yes then we can know that it is in A1
  if the answer is both No  then we can know that it is in A4
  if the answer is Yes and No then we can know that it is in A1
  note that &2 means V2 and V3
            &1 means V1 and V3
  after all
  if there are only 3 elements(a,b,c) left in the array
  then we can use the following steps
  a  1
  b  2
  b  3
  a  4
  if(1 and 2)dfs({arr[0],arr[1]})
  if(!2 and !3)dfs({arr[0],arr[2]})
  if((1 and 2 )or(3 and 4)) dfs({arr[0],arr[1]})
  if((1 and !2) or (!3 and 4))dfs({arr[0],arr[2]})
  else dfs()
*/
#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n;
  cin>>n;
  auto ask=[&](vector<int>arr)
  {
    cout<<"? "<<arr.size();
    for(int i:arr)cout<<" "<<i;
    cout<<endl;
    string ans;
    cin>>ans;
    return (ans=="YES"?1:0);
  };
  auto validate=[&](int x)
  {
    cout<<"! "<<x<<endl;
    string ans;
    cin>>ans;
    if(ans==":)")exit(0);
  };
  vector<int>domain;
  for(int i=1;i<=n;++i)domain.push_back(i);
  while(domain.size()>3)
  {
    int len=domain.size();
    vector<int>q[2];
    for(int i=0;i<len;++i)
    {
      if(i&1)//v1 and V3
      {
        q[0].push_back(domain[i]);
      }
      if(i&2)//V2 and V3
      {
        q[1].push_back(domain[i]);
      }
    }
    int r0=ask(q[0]),r1=ask(q[1]);
    vector<int>nxt;
    for(int i=0;i<len;++i)
    {
      if(r0==(i&1)||(i&2)==2*r1)
      {
        nxt.push_back(domain[i]);
      }
    }
    swap(domain,nxt);
  }
  if(domain.size()<3)
  {
    for(int i=0;i<domain.size();++i)
    {
      validate(domain[i]);
    }
  }
  if(domain.size()==3)
  {
    int r0=ask({domain[0]});
    int r1=ask({domain[1]});
    int rem=-1;
    if(r0==1&&r1==1)rem=2;//double yes the last one is wrong
    if(r0==1&&r1==0)rem=1;
    if(r0==0&&r1==1)rem=0;//when yes and no comes, the only wrong shit is the yes
    else if(r0==0&&r1==0)//double no, we need to check
    {
      int r2=ask(vector<int>{domain[1]});
      if(!r2)rem=1;
      else
      {
        int r3=ask(vector<int>{domain[2]});
        if(r3==1)
        {
          rem=0;
        }
        else
        {
          rem=2;
        }
      }
    }
    for(int i=0;i<3;++i)
    {
      if(i!=rem)validate(domain[i]);
    }
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}