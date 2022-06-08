#include<bits/stdc++.h>
using namespace std;
void dfs(vector<string>&ans,string now_string,int left,int right)
{
    if(left==0&&right==0)
    {
        ans.push_back(now_string);
        return;
    }
    if(left>right)
        return;
    if(left>0)
    {
       
        dfs(ans,now_string+'(',left-1,right);
    }
    if(right>0)
    {
        
        dfs(ans,now_string+')',left,right-1);
    }

}
vector<string> generateParenthesis(int n) {
        vector<string>ans;
        if(n==0)return ans;
        dfs(ans,"",n,n);
        return ans;
}
int main()
{
    vector<string>ans=generateParenthesis(3);
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<endl;
}