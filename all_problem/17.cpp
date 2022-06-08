#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<char>>mapp={{2,{'a','b','c'}},{3,{'d','e','f'}},{4,{'g','h','i'}},{5,{'j','k','l'}},{6,{'m','n','o'}},{7,{'p','q','r','s'}},{8,{'t','u','v'}},{9,{'w','x','y','z'}}};
void dfs(vector<string>&ans,string digits,int index,string now)
{
    if(index==digits.size())
    {
        ans.push_back(now);
        return;
    }
    int order=digits[index]-'0';
    if(order==1){
        dfs(ans,digits,index+1,now);
        return;
    }
    for(int i=0;i<mapp[order].size();++i)
    {
        now.push_back(mapp[order][i]);
        dfs(ans,digits,index+1,now);
        now.pop_back();
    }

}
vector<string> letterCombinations(string digits) {
    vector<string>ans;
    queue<string>q;
    string now_str;
    if(digits.size()==0)return ans;
    dfs(ans,digits,0,now_str);
    return ans;
}
int main()
{
    vector<string>ans=letterCombinations("23");
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i]<<endl;
    }
}