#include<bits/stdc++.h>
using namespace std;
int romanToInt(string s) {
    unordered_map<char,int>map={{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    int res=0;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
       if(i<n-1&&map[s[i]]<map[s[i+1]])
       {
           res-=map[s[i]];
       }
        else
            res+=map[s[i]];
    
    }

    return res;
}
int main()
{   
    cout<<romanToInt("MCMXCIV");

}