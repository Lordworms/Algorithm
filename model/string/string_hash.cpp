#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int pre_one[3001];
int pre_0_num[3001];
int longestSubsequence(string s, int k) {
    memset(pre_0_num,0,sizeof(pre_0_num));
    memset(pre_one,-1,sizeof(pre_one));
    int sum=0,pos=-1;
    for(int i=1;i<=s.size();++i)
    {
        pre_0_num[i]=sum;
        pre_one[i]=pos;
        if(s[i]=='0')++sum;
        if(s[i]=='1')pos=i;
    }
    ll val;
    int ans;
    for(int i=s.size()-1;i>=0;--i)
    {
        val=s[i]-'0';
        ans=0;
        ans+=pre_0_num[i+1];
       
    }            
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}