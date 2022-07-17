#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string tmp=s;
        string ans=s;
        for(int i=0;i<s.size()-1;++i)
        {
            for(int j=i+1;j<s.size();++j)
            {
                swap(tmp[i],tmp[j]);
                if(tmp>ans)
                {
                    ans=tmp;
                }
                swap(tmp[j],tmp[i]);
            }
        }
        return atoi(ans.c_str());
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.maximumSwap(2736);
  return 0;
}