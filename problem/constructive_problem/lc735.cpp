#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //三个条件: 1.当前行星存活 2.栈内有元素 3.栈最后一个为+，当前为-
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(auto& as:asteroids)
        {
            bool alive=true;
            while(alive&&st.size()&&as<0&&st.back()>0)
            {
                alive=st.back()<-as;
                if(st.back()<=-as)
                {
                    st.pop_back();
                }
            }
            if(alive)st.push_back(as);
        }
        return st;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}