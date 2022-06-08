#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>&arr)
{
    int len=arr.size();
    for(int i=0;i<len-1;++i)
    {
        for(int j=0;j<len-i-1;++j)
        {
            if(arr[j+1]<arr[j])
            {
                arr[j]^=arr[j+1];
                arr[j+1]^=arr[j];
                arr[j]^=arr[j+1];
            }
        }
    }

}
void quick_sort(vector<int>&arr,int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int left=l,right=r,key=arr[l];
    while(left<right)
    {
        while(right>left&&arr[right]>=key)right--;
        arr[left]=arr[right];
        while(left<right&&arr[left]<=key)left++;
        arr[right]=arr[left];
    }
    arr[left]=key;
    quick_sort(arr,l,left-1);
    quick_sort(arr,left+1,r);
}
void insert_sort(vector<int>& arr)
{
    int tmp,j;
    for(int i=1;i<arr.size();++i)
    {
        tmp=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>tmp)
        {
            arr[j+1]=arr[j];
            --j;
        }
        if(j!=i-1)
        {
            arr[j+1]=tmp;
        }
    }
}
void shell_sort(vector<int>& arr,int len,int d)
{
    for(int inc=d;inc>0;inc/=2)
    {
        for(int i=inc;i<len;++i)
        {
            int j=i-inc;
            int tmp=arr[i];

        }
    }
    return;

}
void choose_sort(vector<int>& arr)
{
    for(int i=0;i<arr.size();++i)
    {
        int k=i;
        for(int j=i+1;j<arr.size();++i)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        if(i!=k)
        {
            arr[i]^=arr[k];
            arr[k]^=arr[i];
            arr[i]^=arr[k];
        }
    }
}
void heap_sort(vector<int>& arr,int i)
{
    int j,tmp;
    tmp=arr[i];
    j=(i-1)/2;
    while(j>=0&&i!=0)
    {
        if(arr[j]<=tmp)
        {
            break;
        }
        arr[i]=arr[j];
        i=j;
        j=(i-1)/2; 
    }
    arr[i]=tmp;
}
void merge_sort(vector<int>& arr)
{
    return;
}
void count_sort(vector<int>&arr)
{
    return;
}
void buck_sort(vector<int>& arr)
{
    return;
}
void print(vector<int>arr)
{
    for(auto& a:arr)
    {
        cout<<a<<" ";
    }
}
int main()
{
    vector<int>arr={5,4,3,2,1};
    insert_sort(arr);
    print(arr);
}