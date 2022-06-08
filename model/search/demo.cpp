#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>temp;
vector<vector<int>>ans;
void print()
{
    for(int i=0;i<ans.size();++i)
    {
        for(int j=0;j<ans[i].size();++j)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dfs(vector<int>& candidates,int target,int pos,vector<bool>& used)
{
        if(pos==candidates.size())
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=pos;i<candidates.size()&&target-candidates[i]>=0;++i)
        {
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false)
            {
                continue;
            }
            
            used[i]=true;
            temp.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1,used);
            used[i]=false;
            temp.pop_back();
        }
}
void dfs1(vector<int>& candidates,int target,int pos,vector<bool>& used,int sum)
{
        if(pos==candidates.size())
        {
            return;
        }
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=pos;i<candidates.size()&&sum+candidates[i]<=target;++i)
        {
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false)
            {
                continue;
            }
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            used[i]=true;
            //dfs(candidates,target,i+1,used,sum);
            used[i]=false;
            sum-=candidates[i];
            temp.pop_back();
            
           
        }
}
void solution()
{
    //vector<int>arr={10,1,2,7,6,1,5};
    vector<int>arr={2,5,2,1,2};
    int target=5;
    sort(arr.begin(),arr.end());
    vector<bool>used(arr.size(),false);
    dfs(arr,target,0,used);
    //backtracking(arr,target,0,0,used);
}
int main()
{
    solution();
    print();
}