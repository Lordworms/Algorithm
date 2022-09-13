#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}
long long solution(vector<string> queryType, vector<vector<int>> query) {
    unordered_map<int,long long>mp;
    int keyOff=0,valOff=0;
    long long ans=0;
    for(int i=0;i<query.size();++i)
    {
        auto c=queryType[i];
        auto q=query[i];
        if(c=="insert")
        {
            mp[q[0]-keyOff]=q[1]-valOff;
        }
        else if(c=="addToValue")
        {
            valOff+=q[0];
        }
        else if(c=="addToKey")
        {
            keyOff+=q[0];
        }
        else 
        {
            ans+=(mp[q[0]-keyOff]+valOff);
        }
    }
    cout<<keyOff<<" "<<valOff<<endl;
    for(auto q:mp)cout<<q.first<<" "<<q.second<<endl;
    return ans;
}
