#include<bits/stdc++.h>
using namespace std;

    bool cmp(string a,string b)
    {
        return a.size()<b.size();
    }
    bool get_prefix(vector<string>& strs,int length,string check)
    {
        for(int i=0;i<strs.size();++i)
           for(int j=0;j<length;++j)
           {
               if(strs[i][j]!=check[j])
                    return false;
           }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())return "";
        string min_emt=min_element(strs.begin(),strs.end(),cmp);
        int l=0,r=min_emt.size(),mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(get_prefix(strs,length,min_emt)==true)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }   
        return min_emt.substr(0,l);   
    }
    int main()
    {
        


    }