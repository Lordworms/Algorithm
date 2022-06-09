#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int>wx,wy,cx,cy;//表示标杆的值和匹配到的点
    vector<bool>visx,visy;//表示在这次dfs中是否有访问到
    vector<vector<int>>mp;//邻接矩阵存边权
    vector<int>have;//存每个篮子中已经存的数
    int limit=2;//每个篮子里最多存俩
    int minz;//标杆值和边权的差的最小值，表示每次需要修改的值
    int cnty,cntx;
    const int INF=0x3f3f3f3f;
public:
    int dfs(int x)
    {
        visx[x]=true;
        for(int y=0;y<cnty;++y)
        {
            if(!visy[y]&&mp[x][y]!=-1)//当前这个篮子还没被拓展过
            {
                int t=wx[x]+wy[y]-mp[x][y];//计算标杆值和边权的差的最小值
                if(have[y]<limit||dfs(cy[y]))
                {
                    if(have[y]<2)have[y]++;
                    cx[x]=y;
                    return true;
                }
                else if(t>0)minz=min(minz,t);
            }
            
        }  
        return false;
    }
    int KM(vector<int>& nums,int numslots)
    {
        cntx=nums.size(),cnty=numslots;
        visx.resize(cntx,false);visy.resize(cnty,false);
        have.resize(cnty,0);
        cx.resize(cntx,-1);cy.resize(cnty,-1);
        wx.resize(cntx,0);wy.resize(cnty,0);
        mp.resize(cntx,vector<int>(cnty,-1));
        for(int x=0;x<cntx;++x)
        {
            for(int y=0;y<cnty;++y)
            {
                mp[x][y]=nums[x]&(y+1);
                wx[x]=max(wx[x],mp[x][y]);
            }
        }
        for(int x=0;x<cntx;++x)
        {
            while(1)
            {
                minz=INF;
                if(dfs(x))break;   
                for(int x=0;x<cntx;++x)if(visx[x])wx[x]-=minz;
                for(int y=0;y<cnty;++y)if(visy[y])wy[y]+=minz;
            }
        }
        int ans=0;
        for(int x=0;x<cntx;++x)
        {
            ans+=((x+1)&(cx[x]+1));
        }
        return ans;
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        return KM(nums,numSlots);
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int>nums={1,2,3,4,5,6};
  Solution sol;
  cout<<sol.maximumANDSum(nums,3);
  return 0;
}