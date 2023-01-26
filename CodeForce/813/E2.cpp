#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;

struct Node
{
    int l,r,id;
    bool operator<(const Node &W) const
    {
        return l>W.l;    
    }
}query[N];

LL tr[N];
LL cnt[N],ans[N];
vector<vector<int>> ks(N);
int q;

void add(int x,int c)
{
    while(x<N)
    {
        tr[x] += c;
        x += x & -x;
    }
}

LL sum(int x)
{
    LL res = 0;
    while(x)
    {
        res += tr[x];
        x -= x & -x;
    }
    return res;
}

int main()
{
    ios;cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;cin>>l>>r;
        query[i] = {l,r,i};
        int n = r - l + 1;
        ans[i] = 1ll*n*(n-1)*(n-2)/6;
    }
    sort(query,query+q);
    int now = N;
    for(int i=0;i<q;i++)
    {
        int l = query[i].l,r = query[i].r,id = query[i].id;
        while(now>l)
        {
            now--;
            if(now%6==0) ks[now/2].push_back(now);
            if(now%15==0) ks[now/5*2].push_back(now);
            for(int j=2*now;j<N;j+=now)  add(j,cnt[j]++);
            for(auto j:ks[now]) add(j,1);
        }
        ans[id] -= sum(r);
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<'\n';
    return 0;
}
