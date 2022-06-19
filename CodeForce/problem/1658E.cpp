#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    int a,aa,b,bb;
    cin>>n>>k;
    vector<vector<bool>>dp(n,vector<bool>(n,false));
    vector<array<int,5>>map;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>x;
            map.push_back({x,i,j,i+j,j-i});
        }
    }
    sort(map.begin(),map.end(),[&](array<int,5>a,array<int,5>b){return a[0]>b[0];});
    auto check=[&](int i,int j){
        return abs(i-a)<=k&&abs(i-aa)<=k&&abs(j-b)<=k&&abs(j-bb)<=k;
    };
    a=map[0][3],aa=map[0][3],b=map[0][4],bb=map[0][4];
    for(auto& arr:map)
    {
        if(check(arr[3],arr[4]))
        {
            dp[arr[1]][arr[2]]=true;
            a=min(arr[3],a);
            aa=max(arr[3],aa);
            b=min(arr[4],b);
            bb=max(arr[4],bb);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(dp[i][j])
            {
                cout<<"M";
            }
            else
            {
                cout<<"G";
            }
        }
        cout<<endl;
    }
}