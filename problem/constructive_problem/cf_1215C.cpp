/*
    当上界为很小的数的时候，记得枚举分界线
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  int n;string s;
  cin>>n>>s;
  string color(n,'1');
  auto paint=[&](char c)
  {
    char cmax_1=INT_MIN,cmax_2=INT_MIN;
    for(int i=0;i<n;++i)
    {
        if(s[i]<c)
        {
            if(s[i]<cmax_1)
            {
                return false;
            }
            cmax_1=s[i];
            color[i]='1';
        }
        else if(s[i]==c)
        {
            if(s[i]>=cmax_2)
            {
                color[i]='2';
                cmax_2=c;
            }
            else
            {
                color[i]='1';
                cmax_1=c;
            }
        }
        else
        {
            if(s[i]<cmax_2)
            {
                return false;
            }

            cmax_2=s[i];
            color[i]='2';
        }
    }
    return true;
  };
  bool flag=false;
  for(char c='0';c<='9';++c)
  {
    flag=paint(c);
    if(flag)break;
  }
  if(!flag)
  {
    cout<<"-\n"; 
  }
  else
  {
    cout<<color<<'\n';
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}