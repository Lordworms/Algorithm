#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(const int& a,const int& b)
    {
       string aa=to_string(a);
       string bb=to_string(b); 
       if(aa==bb)return true;
       int m=aa.size(),n=bb.size();

       for(int i=0,j=0;;i=(i+1)%m,j=(j+1)%n)
       {
           if(aa[i]>bb[i])
           {
               return true;
           }
           if(aa[i]<bb[i])
           {
               return false;
           }
       }
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans;
        for(auto& num:nums)
        {
            ans+=to_string(num);
        }
        int n=ans.size();
        if((ans[n-1]=='0'&&ans[0]=='0'&&n>1)||(n==1&&ans[0]=='0'))ans="0";
        else
        {
            int i=0;
            while(ans[i]=='0')
            {
                ++i;
            }
            ans=ans.substr(i,n-i+1);
        }
        return ans;
    }
};
int main()
{
    Solution a;
    vector<int>b={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string ans=a.largestNumber(b);
    cout<<ans;
    return 0;
}