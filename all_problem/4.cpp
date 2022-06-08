#include<iostream>
#include<vector>
using namespace std;
vector<double>a={1,3};
vector<double>b={2};

double find_middle(vector<double>nums1,vector<double>nums2)
{
   
    if(nums1.size()>nums2.size())
    {
        return find_middle(nums2,nums1);
    }
    int n=nums2.size(),m=nums1.size();
    int i,j;
    int left=0,right=m;
    int nums1_i_1,nums1_i,nums2_j,nums2_j_1;
    int median_1=0,median_2=0;
    while(left<=right)
    {
        i=(left+right)/2;
        j=(m+n+1)/2-i;
        nums1_i_1=(i==0?INT_MIN:nums1[i-1]);
        nums1_i=(i==n?INT_MAX:nums1[i]);
        nums2_j_1=(j==0?INT_MIN:nums2[j-1]);
        nums2_j=(j==m?INT_MAX:nums2[j]);
        if(nums1_i_1<=nums2_j)
        {
            median_1=max(nums1_i_1,nums2_j_1);
            median_2=min(nums1_i,nums2_j);
            left=i+1;
        }
        else
        {
            right=i-1;
        }

    }
    return (m+n)%2==0?(median_1+median_2)/2.0:median_1;
}

int main()
{
    cout<<find_middle(a,b);

}