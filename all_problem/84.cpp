#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
       int n=heights.size();
       vector<int>maxL(n,-1),maxR(n,-1);
       stack<int>s;
       int ans=0;
       for(int i=0;i<n;++i)
       {
           while(!s.empty()&&heights[s.top()]>=heights[i])
           {
               s.pop();
           }
           maxL[i]=s.empty()?-1:s.top();
           s.push(i);
       }
       while(!s.empty())s.pop();
       for(int i=n-1;i>=0;--i)
       {
           while(!s.empty()&&heights[s.top()]>=heights[i])
           {
               s.pop();
           }
           maxR[i]=s.empty()?n:s.top();
           s.push(i);
       }
       for(int i=0;i<n;++i)
       {
           ans=max(ans,heights[i]*(maxR[i]-maxL[i]-1));
       }
       return ans;
}
int main()
{
    vector<int>heights={1,1};
    cout<<largestRectangleArea(heights);
}