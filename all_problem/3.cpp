#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

void print_map(unordered_map<int,string>m)
{
    auto itr=m.begin();
    while(itr!=m.end())
    {
        cout<<itr->first<<":"<<itr->second<<" ";
        ++itr;
    }

}
int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>window;
        int l=0,r=0,n=s.size();
        int length=0;
        char tmp;
        int res=0;
        while(r<n)
        {
            tmp=s[r];
            if(window.find(tmp)!=window.end()&&window[tmp]>=l)
            {
                l=window[tmp]+1;
                length=r-l;
            }
            window[tmp]=r;
            length++;
            r++;
            
            res=max(length,res);
        }
        return res;
}
int main()
{
   cout<<lengthOfLongestSubstring("aaaaa");

}





