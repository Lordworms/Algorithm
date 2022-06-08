#include<bits/stdc++.h>
using namespace std;

void print(int next[],int n)
{
    
    for(int i=0;i<n;++i)
    {
        cout<<next[i]<<" ";
    }
}
void get_next(vector<int>& nxt,string s)
{
    int j,m=s.size();
    for(int i=1;i<m;++i)
    {
        j=nxt[i-1];
        while(j!=-1&&s[j+1]!=s[i])
        {
            j=nxt[j];
        }
        if(s[j+1]==s[i])
        {
            nxt[i]=j+1;
        }
    }
} 
bool kmp(string ori,string pat)
{
    int n=ori.size(),m=pat.size();
    vector<int>nxt(m,-1);
    get_next(nxt,pat);
    int ppos=0,spos=0;
    while(spos<ori.size())
    {
        if(ori[spos]==pat[ppos])++ppos,++spos;
        else if(ppos==pat.size())return true;
        else if(ppos){ppos=nxt[ppos]==-1?0:nxt[ppos];}
        else{spos++;}
    }
    return false;
} 
int main()
{
    cout<<kmp("ababab","ababab");
    return 0;

}