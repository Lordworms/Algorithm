#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>ans;
        int left=0,right=n-1,up=0,down=m-1;
        while(left<=right||up<=down)
        {
            for(int i=left;i<=right;++i)
            {
                ans.push_back(matrix[up][i]);
            }
            up++;
            if(up>down)break;
            for(int i=up;i<=down;++i)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right;i>=left;--i)
            {
                ans.push_back(matrix[down][i]);
            }
            down--;
            for(int i=down;i>=up;--i)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(left>=right)break;
        }          
        return ans;

}
int main()
{
    vector<vector<int>>matrix={{2,5,8},{4,0,-1}};
    spiralOrder(matrix);


}