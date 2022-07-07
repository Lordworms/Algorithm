/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int d,lim;
  cin>>d>>lim;
  vector<int>lowb(d,0),upb(d,0);
  for(int i=0;i<d;++i)
  {
    cin>>lowb[i]>>upb[i];
  }
  int day=0;
  vector<int>spent(d,0);
  while(lim&&day<d)
  {
    if(lim>=upb[day])
    {
       spent[day]=upb[day];
        lim-=upb[day];
    }
    else

    {
        spent[day]=lim;
        lim=0;
    }
    ++day;
  }
  if(day<d){cout<<"NO";return 0;}
  cout<<"YES"<<endl;
  for(int i=0;i<d;++i)cout<<spent[i]<<" ";
  return 0;
}