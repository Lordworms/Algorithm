#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==0)return ans;
        ans.push_back({1});
        if(numRows==1)return ans;
        ans.push_back({1,1});
        if(numRows==2)return ans;
        for(int len=3;len<numRows+1;++len)
        {
            vector<int>now(len,1);
            for(int i=0;i<len;++i)
            {
                if(i!=0&&i!=len-1)
                {
                    now[i]=ans[len-2][i-1]+ans[len-2][i];
                }
            }
            ans.push_back(now);
        }
        return ans;
}
int main()
{
    vector<vector<int>>ans=generate(5);
    return 0;
}