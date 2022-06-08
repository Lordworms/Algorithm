#include<bits/stdc++.h>
using namespace std;
void merge_sort(vector<int>& data,int left,int right)
{
    int i=left,mid=(right+left)>>1,j=mid+1;
    vector<int>tmp;
    while(i<=mid&&j<=right)
    {
        if(data[i]<data[j])
        {
            tmp.emplace_back(data[i++]);
        }
        else
        {
            tmp.emplace_back(data[j++]);
        }
    }
    while(i<=mid)tmp.emplace_back(data[i++]);
    while(j<=right)tmp.emplace_back(data[j++]);
    for(int i=0;i<tmp.size();++i)
    {
        data[left+i]=tmp[i];
    }
}
void merge(int left,int right,vector<int>& data)
{
    if(left<right)
    {
        int mid=(left+right)>>1;
        merge(left,mid,data);
        merge(mid+1,right,data);
        merge_sort(data,left,right);
    }

}
void q_sort(int left,int right,vector<int>& data)
{
    int key=data[left];
    int i=left,j=right;
    if(left>=right)return;
    while(i<j)
    {
        
        while(i<j&&data[j]>=key)--j;
        data[i]=data[j];
        while(i<j&&data[i]<=key)++i;
        data[j]=data[j];
    }
    data[i]=key;
    q_sort(left,i-1,data);
    q_sort(i+1,right,data);
}

int main()
{
    vector<int>data={5,4,3,2,1};
    q_sort(0,data.size()-1,data);
    for(auto& d:data)
    {
        cout<<d<<" ";

    }
}