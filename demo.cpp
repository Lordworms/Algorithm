#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0',c=getchar();}
    return x*f;
}

void ask(int x,int y){cout<<"? "<<x<<" "<<y<<endl;}
void ans(int x,int y){cout<<"! "<<x<<" "<<y<<endl;}

void solve()
{
    int n;cin>>n;
    vector<int>v;
    for(int i=1;i<=n;i++)v.push_back(i);
    while(v.size()>2)
    {
        int a=v.back();v.pop_back();int b=v.back();v.pop_back();int c=v.back();v.pop_back();
        ask(a,b);int op1;cin>>op1;ask(a,c);int op2;cin>>op2;
        if(op1==op2)v.push_back(b),v.push_back(c);
        else 
        {
            if(op1<op2)v.push_back(a),v.push_back(c);
            else v.push_back(a),v.push_back(b);
        }
    }
    ans(v[0],v[1]);int x;cin>>x;
}

int main()
{
    int T=read();
    while(T--)solve();
    return 0;
}