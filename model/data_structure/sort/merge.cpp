#include<bits/stdc++.h>
using namespace std;
void merge(int st,int end,vector<int>&data)
{
    vector<int>tmp;
    int mid=(st+end)>>1;
    int i=st,j=mid+1;
    while(i<=mid&&j<=end)
    {
        if(data[i]<=data[j])
        {
            tmp.push_back(data[i++]);
        }
        else
        {
            tmp.push_back(data[j++]);
        }
    }
    while(i<=mid)
    {
        tmp.push_back(data[i++]);
    }
    while(j<=end)
    {
        tmp.push_back(data[j++]);
    }
    for(int i=0;i<tmp.size();++i)
    {
        data[st+i]=tmp[i];
    }
}
void merge_sort(int st,int end,vector<int>&data)
{
    
    if(st<end)
    {
    int mid=(st+end)>>1;
    merge_sort(st,mid,data);
    merge_sort(mid+1,end,data);
    merge(st,end,data);
    }
}
int main()
{
    vector<int>data={4,3,2,1};
    merge_sort(0,data.size()-1,data);
    return 0;
}