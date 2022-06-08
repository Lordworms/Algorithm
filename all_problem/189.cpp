#include<bits/stdc++.h>
using namespace std;
    void rotate(vector<int>& nums, int k) {
        bool flag=false;
        int now=nums[0],pos,pre;
        int i=0;
        int n=nums.size();
        int count=0;
        while(!flag)
        {
            pos=(i+k)%n;
            swap(nums[pos],now);
            i=pos;
            count++;
            if(count==n)
            {
                flag=true;
                break;
            }
        }
    }

int main()
{
    vector<int>nums={-1,-100,3,99};
    rotate(nums,2);
    return 0;   
}