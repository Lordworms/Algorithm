#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    const int MAXN=1e7+7;
    int row,col;
    vector<int>fa;  
public:
    int getIndex(int i,int j){return (i*col)+j;};
    int getFa(int x){return fa[x]==x?x:getFa(fa[x]);}
    int minimumEffortPath(vector<vector<int>>& heights) {
        row=heights.size(),col=heights[0].size();
        vector<vector<int>>edges;
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                int index=getIndex(i,j);
                if(i>0)edges.push_back({index-col,index,abs(heights[i][j]-heights[i-1][j])});
                if(j>0)edges.push_back({index-1,index,abs(heights[i][j]-heights[i][j-1])});
            }
        }
        sort(edges.begin(),edges.end(),[&](vector<int>a,vector<int>b){return a[2]<b[2];});
        int ans=INT_MIN,n=col*row;
        fa.resize(n);
        for(int i=0;i<n;++i)fa[i]=i;
        int cnt=0;
        for(auto& a:edges)
        {
            
            fa[getFa(a[0])]=getFa(a[1]);
            int fx=getFa(0);
            int fy=getFa(n-1);
            if(fx==fy){ans=a[2];break;}
            
        }
        return ans;

    }
};
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   vector<vector<int>>heights={{1,2,2},{3,8,2},{5,3,5}};
   Solution sol;
   cout<<sol.minimumEffortPath(heights);
   return 0;
}
