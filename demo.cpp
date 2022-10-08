#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size(),ans=n;
        stack<int>s;
        vector<int>rm(n),lm(n);
        for(int i=0;i<n;++i)
        {
            while(!s.empty()&&rat[i]>rat[s.top()])
            {
                rm[s.top()]=i;
                s.pop();
            }
            if(s.empty()||rat[i]<rat[s.top()])s.push(i);
        }
        while(!s.empty())
        {
            rm[s.top()]=n+1;
            s.pop();
        }
        for(int i=n-1;i>=0;--i)
        {
            while(!s.empty()&&rat[i]>rat[s.top()])
            {
                lm[s.top()]=i;
                s.pop();
            }
            if(s.empty()||rat[i]<rat[s.top()])s.push(i);
        }
        while(!s.empty())
        {
            lm[s.top()]=-1;
            s.pop();
        }
        for(int i=0;i<n;++i)
        {
            if(i==0)
            {
                if(rm[i]>i+1)++ans;
            }
            else if(i==n-1)
            {
                if(lm[i]<i-1)++ans;
            }
            else
            {
                if(rm[i]>i+1&&lm[i]<i-1)++ans;
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int>vec={1,0,2};
  sol.candy(vec);
  return 0;
}