#include<bits/stdc++.h>
using namespace std;
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1||points.size()==2)
        {
            return points.size();
        }
        
        int maxnum=2;
        int n=points.size();
        for(int i=0;i<n;++i)
        {
            unordered_map<double,int>mp;
            for(int j=i+1;j<n;++j)
            {
                double k=(points[j][1]-points[i][1])*1.0/((points[j][0]-points[i][0]));
                if(mp.count(k))
                    mp[k]++;
                else mp[k]=2;
                maxnum=max(maxnum,mp[k]);
            }
        }
        return maxnum;
    }
int main()
{
    vector<vector<int>>a={{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout<<maxPoints(a);
}