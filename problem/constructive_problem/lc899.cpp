/*
    给定一个字符串 s 和一个整数 k 。你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾。
返回 在应用上述步骤的任意数量的移动后，字典上最小的字符串 。
    首先明确一点，当k>1的时候，我门总是可以通过交换来把该字符串变成升序状态(类似冒泡排序)
    所以只需要管k==1的情况，这相当于把圆环切开
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        else 
        {
            string ans=s,tmp=s;
            for(int i=0;i<s.size();++i)
            {
                tmp+=s[i];
                tmp.erase(tmp.begin());
                cout<<tmp<<endl;
                ans=min(ans,tmp);
            }
            return ans;
        }
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}