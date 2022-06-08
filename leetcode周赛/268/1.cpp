#include <bits/stdc++.h>
using namespace std;
 
string digitSum(string s, int k) {
    string ans;
    int n=s.size();
    while(n>k)
    {
      int round=n%k==0?n/k:n/k+1;
      for(int i=0;i<round;++i)
      {
          int now=0;
          for(int j=0;j<k&&i*k+j<n;++j)
          {
              now+=s[i*k+j]-'0';
          }
          ans+=to_string(now);
      }
      s=ans;
      ans="";
      n=s.size();
    }   
    return s; 
}
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout<<digitSum("1234",2);
   return 0;
}
