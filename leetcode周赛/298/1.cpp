#include <bits/stdc++.h>
using namespace std;
    string greatestLetter(string s) {
        unordered_set<char>mp;
        for(auto& ss:s){
            mp.insert(ss);
        }
        string ans="";
        for(auto& k:mp)
        {
            if(k>='A'&&k<='Z'&&mp.count(k+'A'-'a'))
            {
                if(ans==""||k>ans[0])
                {
                    ans=k;
                }
            }
        }
        return ans;
        
    }

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout<<greatestLetter("lEeTcOdE");
  return 0;
}