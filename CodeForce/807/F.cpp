#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;cin>>n;
  string s(n,0),str,tmp;
  int m=n/3;
  int q1,q2,q3,q4,q5;
  auto query=[&](string& s)
  {
    int q;
    cout<<s<<'\n';
    cin>>q;
    return q;
  };
  str=string(n,'T');
  q1=query(str);
  for(int i=0;i<m;++i)
  {
    tmp=str;tmp[i]=tmp[i+m]='F';
    q2=query(tmp);
    if(q1==q2-2)s[i]=s[i+m]='F';
    if(q1==q2+2)s[i]=s[i+m]='T';
    //otherwise it is TF or FT
  }
  str=string(m,'F')+string(n-m,'T');
  q3=query(str);
  for(int i=0;i<m;++i)
  {
    if(!s[i])
    {
      tmp=str;
      tmp[i]='T',tmp[i+m]=tmp[i+2*m]='F';
      q4=query(tmp);
      if(q3==q4+3)s[i]='F',s[i+m]='T',s[i+2*m]='T';
      if(q3==q4+1)s[i]='F',s[i+m]='T',s[i+2*m]='F';
      if(q3==q4-1)s[i]='T',s[i+m]='F',s[i+2*m]='T';
      if(q3==q4-3)s[i]='T',s[i+m]='F',s[i+2*m]='F';
    }
  }
  for(int i=0;i<n;++i)
  {
    if(s[i]!=0)continue;
    tmp=string(n,'T');
    tmp[i]='F';
    q5=query(tmp);
    s[i]=q5>q1?'F':'T';
  }
  cout<<s<<'\n';
  return;
}
int main()
{
  int T=1;
  while(T--)
  {
    solve();
  }
  return 0;
}