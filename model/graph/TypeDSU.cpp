/*
    the enemy of i is i+n, so if x and y are enemies, then we merge(y,x+n) merge(x,y+n)
    and it is ok now!
*/
#include <bits/stdc++.h>
using namespace std;
struct TDSU
{
    vector<int>f,siz;
    TDSU(int n):f(n),siz(n){iota(f.begin(),f.end(),0);}
    int fa(int x)
    {
        while(x!=f[x])x=f[x]=f[f[x]];
        return x;
    }
    
};