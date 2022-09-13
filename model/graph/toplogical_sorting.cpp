#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
vector<int>G[MAXN];
vector<int>in;
int n;
vector<int>top_sorting()
{
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<n;++i)if(in[i]==0)
    {
        ans.push_back(i);
    }
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        ans.push_back(x);
        for(int u:G[x])
        {
            if(--in[u]==0)
            {
                q.push(u);
            }
        }
    }
    return ans;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}