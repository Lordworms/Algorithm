#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int index=0;
        unordered_map<string,int>myhash;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();++i)
        {
            string tmp=strs[i];
            sort(tmp.begin(),tmp.end());
            if(myhash[tmp]>0)
            {
                ans[myhash[tmp]-1].push_back(strs[i]);
            }
            else
            {
                index++;
                myhash[tmp]=index;
                ans.push_back({strs[i]});
            }    
        }
        return ans;

}
int main()
{
    vector<string>data={"eat","tea","tan","ate","nat","bat"};
    groupAnagrams(data);
}