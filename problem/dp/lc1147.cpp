/*
    题意：你会得到一个字符串 text 。你应该把它分成 k 个子字符串 (subtext1, subtext2，…， subtextk) ，要求满足:
        subtexti 是非空字符串
        所有子字符串的连接等于 text ( 即subtext1 + subtext2 + ... + subtextk == text )
        subtexti == subtextk - i + 1 表示所有 i 的有效值( 即 1 <= i <= k )
        返回k可能最大值。
    题解：循环kmp即可，简单题

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_next(string s)
    {
        int j,n=s.size();
        vector<int>nxt(n,-1);
        for(int i=1;i<n;++i)
        {
            j=nxt[i-1];
            while(j!=-1&&s[j+1]!=s[i])j=nxt[j];
            if(s[j+1]==s[i])    
            {
            nxt[i]=j+1; 
            }
        }
        int ans=nxt[n-1];
        while(ans!=-1&&nxt[ans]!=-1)ans=nxt[ans];
        return ans+1;
    }
    int longestDecomposition(string text) {
        int ans=0,sub,n;
        while(text.size()>0)
        {   
            n=text.size();
            sub=get_next(text);
            if(sub==0){ans+=1;break;}
            text=text.substr(sub,n-2*sub);
            ans+=2;
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  sol.longestDecomposition("elvtoelvto");
  return 0;
}