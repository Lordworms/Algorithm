#include<bits/stdc++.h>
using namespace std;
string solution(string s)
{
    int len=s.size();
    if(len==1)return s;
    if(len==2)
    {
        if(s[0]==s[1])
            return s;
        string res;
        res+=s[0];
        return res;
    }
    vector<vector<bool>>dp(len,vector<bool>(len));
    //dp数组初始化
    for(int i=0;i<len;++i)
    {
        dp[i][i]=true;
        if(i!=len-1)
        {
            dp[i][i+1]=(s[i]==s[i+1])?true:false;
        }
    }
    int begin=0,maxlen=0;
    //开始扫描，先枚举子串长度
    for(int L=2;L<=len;++L)
    {
        //枚举开始位置 
        for(int i=0;i<len;++i)
        {
            int j=i+L-1;
            if(j>=len)
            {
                break;
            }
            if(s[i]==s[j])
            {
                if(dp[i][j]!=true)
                    dp[i][j]=dp[i+1][j-1];
                if(L>maxlen&&dp[i][j]==true)
                {
                    maxlen=L;
                    begin=i;
                }
            }
        }
    }
    if(maxlen==0)return s[0];
    return s.substr(begin,maxlen);
}
int main()
{
    cout<<solution("abcda");

}

