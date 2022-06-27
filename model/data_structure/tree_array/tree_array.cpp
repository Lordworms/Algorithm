#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int c[MAXN],a[MAXN];
int n;
/*
    树状数组的思想：用一个辅助数组tree，tree中每个下标的末尾0的数量设为k，那么每个下标管辖的数字数量就是2^k然后不断求和即可

*/
//获得x末尾有多少个0
int lowbit(int x)
{
    return x&-x;
}
int getSum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void update(int x,int value)
{
    a[x]+=value;
    while(x<=n)
    {
        c[x]+=value;
        x+=lowbit(x);
    }
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
    int x,v,T;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    
   return 0;
}
