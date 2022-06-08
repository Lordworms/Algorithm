#include <bits/stdc++.h>
using namespace std;
bool manacher(string s)
{
    string now="@";
    for(char c:s)
    {
        now+='#';
        now+=c;
    }
    now+='#';
    int R=0,mid=0,n=now.size();
    vector<int>P(n+1,0);
    for(int i=1;i<n;++i)
    {
        P[i]=R>i?min(P[2*mid-i],R-i):0;//下面如果是+1 -1就为0
        while(i-P[i]-1>=0&&now[i+P[i]+1]==now[i-P[i]-1])++P[i];
        if(i+P[i]>R)
        {
            R=i+P[i];
            mid=i;
        }
    }
    return P[n/2]==s.size();
}
int main(){
    
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
    cout<<manacher("aacecaa");
   return 0;
}
