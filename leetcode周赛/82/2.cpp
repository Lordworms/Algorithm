/*
题意：
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        set<int>st;
        for(int i=0;i<passengers.size();++i)st.insert(passengers[i]);
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        reverse(passengers.begin(),passengers.end());
        int ans=0;
        for(auto&x:buses)
        {
            int y=capacity;
            while(y&&passengers.size()&&passengers.back()<=x)
            {
                --y;
                ans=passengers.back();
                passengers.pop_back();
            }
            if(y)ans=x;
        }
        while(st.count(ans))--ans;
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
 
  vector<int>bus={18,8,3,12,9,2,7,13,20,5};
  vector<int>pa={13,10,8,4,12,14,18,19,5,2,30,34};
  sort(bus.begin(),bus.end());
  sort(pa.begin(),pa.end());
  for(int i=0;i<bus.size();++i)cout<<bus[i]<<" ";
  cout<<endl;
  for(int i=0;i<pa.size();++i)cout<<pa[i]<<" ";
  cout<<endl;
  sol.latestTimeCatchTheBus(bus,pa,1);
  return 0;
}