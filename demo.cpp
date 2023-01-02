#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long;
    struct node
    {
        int id;
        ll st,pr;
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int now=INT_MAX;
        for(int i=0;i<tasks.size();++i)
        {
            now=min(now,tasks[i][0]);
        }
        auto cmp=[&](node a,node b)
        {
            if(a.pr==b.pr)
            {
                return a.st>b.st;
            }
            return a.pr>b.pr;
        }; 
        vector<int>ans;
        priority_queue<node,vector<node>,decltype(cmp)>q(cmp);
        for(int i=0;i<tasks.size();++i)
        {
            q.push({i,tasks[i][0],tasks[i][1]});
        }
        vector<node>tmp;
        while(!q.empty())
        {
           while(!q.empty()&&q.top().st>now)
           {
               tmp.push_back(q.top());
               q.pop();
           }
           node tt;
           bool flag=false;
           if(q.empty()&&tmp.size())
           {
               tt=tmp[0];
               flag=true;
           }
           else
           {
               tt=q.top();
               q.pop();
           }
           now+=tt.pr;
           ans.push_back(tt.id);
           int start=0;
           if(flag)
           {
               start++;
           }
           for(int i=start;i<tmp.size();++i)
           {
               q.push(tmp[i]);
           }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution Sol;
  vector<vector<int>>task={{1,2},{2,4},{3,2},{4,1}};
  Sol.getOrder(task);
  return 0;
}