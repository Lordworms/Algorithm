/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMax(string s)
    {
        int n=s.size();
        vector<int>sa(n+1,0),rk(n+1,0);
        for(int i=1;i<=n;++i)sa[i]=i,rk[i]=s[i-1];
        int k=0;
        auto cmp=[&](int i,int j){
            if(rk[i]!=rk[j])
            {
                return rk[i]<rk[j];
            }
            int ri=(i+k<=n?rk[i+k]:-1);
            int rj=(j+k<=n?rk[j+k]:-1);
            return ri<rj;
        };
        vector<int>rk2(n+1,0);
        for(k=1;k<=n;k<<=1)
        {
            sort(sa.begin()+1,sa.begin()+n+1,cmp);
            rk2[sa[1]]=1;
            for(int i=2;i<=n;++i)
            {
                rk2[sa[i]]=rk2[sa[i-1]]+cmp(sa[i-1],sa[i]);;
            }
            for(int i=1;i<=n;++i)rk[i]=rk2[i];
        }
        return rk[n];
    }
    string lastSubstring(string s) {
        int num=getMax(s);
        return s.substr(num,s.size()-num+1);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
return 0;
}