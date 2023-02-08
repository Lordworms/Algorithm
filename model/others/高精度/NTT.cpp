#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 20005
#define M 40005
#define ll long long
#define a hz.w
#define b kz.w
#define c kzkz.w
#define d kzzf.w
#define P 998244353
#define inv(x) ksm(x,P-2)
#define zero(x) (x.w[0]==1 && x.w[1]==0)
using namespace std;
char orz[N];
int rev[M];
int G[2][25];
int e[M],f[M];
int ksm(int x,int y);
void NTT(int *g,int t,int s);
struct BigNumber
{
    int w[N];
    void set0()
    {
        w[0]=1,w[1]=0;
    }
    void set1()
    {
        w[0]=1,w[1]=1;
    }
    void read()
    {
        scanf("%s",orz);
        w[0]=strlen(orz);
        for (int i=0;i<w[0];i++)
            w[w[0]-i]=orz[i]-'0';
    }
}s,t;
BigNumber kz,kzkz,kzzf;
void write(BigNumber kz)
{
    for (int i=b[0];i>=1;i--)
        putchar(b[i]+'0');
    putchar('\n');
}
bool operator < (BigNumber hz,BigNumber kz)
{
    if (a[0]!=b[0])
        return a[0]<b[0];
    for (int i=a[0];i>=1;i--)
        if (a[i]!=b[i])
            return a[i]<b[i];
    return false;
}
bool operator <= (BigNumber hz,BigNumber kz)
{
    if (a[0]!=b[0])
        return a[0]<b[0];
    for (int i=a[0];i>=1;i--)
        if (a[i]!=b[i])
            return a[i]<b[i];
    return true;
}
bool operator > (BigNumber hz,BigNumber kz)
{
    if (a[0]!=b[0])
        return a[0]>b[0];
    for (int i=a[0];i>=1;i--)
        if (a[i]!=b[i])
            return a[i]>b[i];
    return false;
}
bool operator >= (BigNumber hz,BigNumber kz)
{
    if (a[0]!=b[0])
        return a[0]>b[0];
    for (int i=a[0];i>=1;i--)
        if (a[i]!=b[i])
            return a[i]>b[i];
    return true;
}
bool operator == (BigNumber hz,BigNumber kz)
{
    if (a[0]!=b[0])
        return false;
    for (int i=a[0];i>=1;i--)
        if (a[i]!=b[i])
            return false;
    return true;
}
bool operator != (BigNumber hz,BigNumber kz)
{
    if (a[0]!=b[0])
        return true;
    for (int i=a[0];i>=1;i--)
        if (a[i]!=b[i])
            return true;
    return false;
}
BigNumber operator + (BigNumber hz,BigNumber kz)
{
    int ws=max(a[0],b[0]);
    int jw=0;
    for (int i=1;i<=ws;i++)
    {
        if (a[0]<i)
            a[i]=0;
        if (b[0]<i)
            b[i]=0;
        b[i]=b[i]+a[i]+jw;
        jw=b[i]/10;
        b[i]%=10;
    }
    while (jw)
    {
        ws++;
        b[ws]=jw%10;
        jw/=10;
    }
    b[0]=ws;
    return kz;
}
BigNumber operator - (BigNumber hz,BigNumber kz)
{
    int ws=max(a[0],b[0]);
    for (int i=1;i<=ws;i++)
    {
        if (i>b[0])
            b[i]=a[i]; else
            b[i]=a[i]-b[i];
        if (b[i]<0)
        {
            b[i]+=10;
            a[i+1]--;
        }
    }
    while (!b[ws] && ws>1)
        ws--;
    b[0]=ws;
    return kz;
}
BigNumber operator * (BigNumber hz,BigNumber kz)
{
    int la=a[0],lb=b[0];
    int s=1,l=0;
    while (s<la+lb)
    {
        s <<=1;
        l++;
    }
    rev[0]=0;
    for (int i=1;i<s;i++)
        rev[i]=(rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
    e[0]=f[0]=0;
    for (int i=1;i<=la;i++)
        e[i-1]=a[i];
    for (int i=1;i<=lb;i++)
        f[i-1]=b[i];
    for (int i=la;i<s;i++)
        e[i]=0;
    for (int i=lb;i<s;i++)
        f[i]=0;
    NTT(e,0,s);
    NTT(f,0,s);
    for (int i=0;i<s;i++)
        e[i]=(ll)e[i]*f[i]%P;
    NTT(e,1,s);
    int invs=inv(s);
    for (int i=s;i>=1;i--)
        e[i]=(ll)e[i-1]*invs%P;
    e[0]=0;
    for (int i=1;i<=la+lb;i++)
    {
        e[i+1]+=e[i]/10;
        e[i]%=10;
    }
    a[0]=la+lb;
    while (!e[a[0]] && a[0]>1)
        a[0]--;
    for (int i=1;i<=a[0];i++)
        a[i]=e[i];
    return hz;
}
BigNumber operator / (BigNumber hz,BigNumber kz)
{
    for (int i=0;i<=a[0];i++)
        c[i]=d[i]=0;
    d[0]=1;
    for (int i=a[0];i>=1;i--)
    {
        if (!(d[0]==1 && d[1]==0))
        {
            for (int i=d[0];i>=1;i--)
                d[i+1]=d[i];
            d[1]=a[i];
            d[0]++;
        } else
            d[1]=a[i];
        while (kzzf>=kz)
        {
            kzzf=kzzf-kz;
            c[i]++;
        }
    }
    c[0]=a[0];
    while (!c[c[0]] && c[0]>1)
        c[0]--;
    return kzkz;
}
BigNumber operator % (BigNumber hz,BigNumber kz)
{
    for (int i=0;i<=a[0];i++)
        d[i]=0;
    d[0]=1;
    for (int i=a[0];i>=1;i--)
    {
        if (!(d[0]==1 && d[1]==0))
        {
            for (int i=d[0];i>=1;i--)
                d[i+1]=d[i];
            d[1]=a[i];
            d[0]++;
        } else
            d[1]=a[i];
        while (kzzf>=kz)
            kzzf=kzzf-kz;
    }
    return kzzf;
}
void operator += (BigNumber &kz,BigNumber hz)
{
    kz=kz+hz;
}
void operator -= (BigNumber &kz,BigNumber hz)
{
    kz=kz-hz;
}
void operator *= (BigNumber &kz,BigNumber hz)
{
    kz=kz*hz;
}
void operator /= (BigNumber &kz,BigNumber hz)
{
    kz=kz/hz;
}
void operator %= (BigNumber &kz,BigNumber hz)
{
    kz=kz%hz;
}
BigNumber Number_Turn_BigNumber(ll x)
{
    if (x==0)
    {
        kz.set0();
        return kz;
    }
    b[0]=0;
    while (x)
    {
        b[++b[0]]=x%10;
        x/=10;
    }
    return kz;
}
ll BigNumber_Turn_Number(BigNumber kz)
{
    ll y=0;
    for (int i=b[0];i>=1;i--)
        y=y*10+b[i];
    return y;
}
void NTT(int *q,int t,int s)
{
    for (int i=0;i<s;i++)
        if (i<rev[i])
            swap(q[i],q[rev[i]]);
    for (int mid=1,o=1;mid<s;mid <<=1,o++)
        for (int j=0;j<s;j+=(mid << 1))
        {
            int g=1;
            for (int k=0;k<mid;k++,g=(ll)g*G[t][o]%P)
            {
                int x=q[j+k],y=(ll)g*q[j+k+mid]%P;
                q[j+k]=(x+y)%P;
                q[j+k+mid]=(x-y+P)%P;
            }
        }
}
int ksm(int x,int y)
{
    int ans=1;
    while (y)
    {
        if (y & 1)
            ans=(ll)ans*x%P;
        x=(ll)x*x%P;
        y >>=1;
    }
    return ans;
}
void Pre()
{
    G[0][23]=ksm(3,(P-1)/(1 << 23));
    G[1][23]=inv(G[0][23]);
    for (int i=22;i>=1;i--)
    {
        G[0][i]=(ll)G[0][i+1]*G[0][i+1]%P;
        G[1][i]=(ll)G[1][i+1]*G[1][i+1]%P;
    }
}
#undef a
#undef b
#undef c
#undef d
int main()
{
    Pre();
    s.read(),t.read();
    write(s+t);
    if (s<t)
        putchar('-'),write(t-s); else
        write(s-t);
    write(s*t);
    write(s/t);
    write(s%t);
    return 0;
}
