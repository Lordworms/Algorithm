/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lastSubstring(string s) {
        int pos,n=s.size();
        char maxstr=0;
        for(int i=n-1;i>=0;--i)
        {
            if(s[i]>=maxstr)
            {
                maxstr=s[i];
                pos=i;
            }
        }
        int r=pos+1;
        while(r<n)
        {
            if(s[r]!=maxstr)//下一个元素不是最大元素
            {
                ++r;
            }
            else//逐位比较
            {   
                int j=pos+1,k=r+1;
                while(j<r&&k<n)
                {
                    if(s[j]==s[k])
                    {
                        ++j,++k;
                    }
                    else
                    {
                        if(s[j]<s[k])
                        {
                            pos=r;
                        }
                        r=k;
                        break;
                    }
                }
                if(j==r||k==n)r=k;//大坑，不然你的r没法动
            }
        }
        return s.substr(pos);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  cout<<sol.lastSubstring("abab");
  return 0;
}