#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> field, vector<vector<int>> figure) {
    int tmp[3][3];
    memset(tmp,0,sizeof(tmp));
    function<void(int,int)>restore=[&](int x,int y)
    {
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
               
               field[x+i][y+j]=tmp[i][j];
              
            }
        }
    };
    function<bool(int,int)>check=[&](int x,int y)
    {
        memset(tmp,0,sizeof(tmp));
        for(int i=0;i<3;++i)for(int j=0;j<3;++j)tmp[i][j]=field[x+i][y+j];
        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                if(figure[i][j]!=0&&field[x+i][y+j]!=0){
                    restore(x,y);
                    return false;
                }
                if(figure[i][j]==1)field[x+i][y+j]=figure[i][j];
            }
        }
        for(int i=x;i<x+3;++i)
        {
            bool flag=true;
            for(int j=0;j<field[0].size();++j)
            {
                if(field[i][j]!=1){
                  
                  flag=false; 
                  
                }
            }
            if(flag)return true;
        }
        restore(x,y);
        return false;
    };
    int m=field.size(),n=field[0].size();
    for(int i=m-3;i>=0;--i)
    {
        for(int j=n-3;j>=0;--j)
        {
            if(check(i,j))
            {
                return j;
            }
        }
    }
    return -1;
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>>arr={{0,0,0,0,0}, 
 {0,0,0,0,0}, 
 {0,0,0,0,0}, 
 {1,1,0,1,0}, 
 {1,0,1,0,1}};
  vector<vector<int>>fig={{1,1,1}, 
 {1,0,1}, 
 {1,0,1}};
  cout<<solution(arr,fig);
  return 0;
}