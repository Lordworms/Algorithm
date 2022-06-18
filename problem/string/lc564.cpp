/*
    题意：给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。
        “最近的”定义为两个整数差的绝对值最小。
    题解：字符串模拟题，首先我们的答案肯定在这三个范围内
        1.这个数的前半部分复制到右半部分的结果
        2.前半部分-1后位数发生改变的结果
        3.前半部分+1后位数发生改变的结果
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    using ll=unsigned long long;
public:
    vector<ll>getList(string str)
    {
      int len=str.size();
      ll prefix=stoull(str.substr(0,(len+1)>>1));
      vector<ll>canList={
          (ll)pow(10,len-1)-1,
          (ll)pow(10,len)+1
      };
      for(int num:{prefix-1,prefix,prefix+1})
      {
          string pre=to_string(num);
          string can=pre+string(pre.rbegin()+(len&1),pre.rend());
          canList.push_back(stoull(can));
      }
      return canList;
    }
    string nearestPalindromic(string n) 
    {
        vector<ll>lis=getList(n);
        ll ans=-1;
        ll now=stoull(n);
        for(auto& num:lis)
        {
          if(num==now)continue;
          if(ans==-1||llabs(num-now)<llabs(ans-now)||llabs(num-now)==llabs(ans-now)&&num<ans)
          {
            ans=num;
          }
        }
        return to_string(ans);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  return 0;
}