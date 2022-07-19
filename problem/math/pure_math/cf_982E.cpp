/*
    这题学问还是挺多的，首先是把一个简单的矩形反射问题修改为多个矩形，然后我们可以发现，我们需要的为
    bm=an+y0-x0的解
    首先我们可以先进行特判，把vx=0/vy=0的情况给特判掉（平行于坐标轴的情况）
    随后由于我们是根据vx=1,vy=1的情况
    所以对于vx=-1或者vy=-1的情况，我们需要更改x和y的值，
    这里又是另外一门逻辑了，在矩形内我们对于某个点进行镜面对称，应该是关于y=m/n*x对称，所以x=n-x y=m-y为对称点
    注意我们进行对称之后到达的终点应该也是对称的，所以需要还原回去（这里我们是做了方向向量=(1,1)的统一）
    之后我们需要最小的a和b的值
    又一个地方不太明白，为什么算出来的a需要对m/gcd(n,m)取模
    (现在想明白了我们的解是严格满足x<|a|,y<|b|，所以要满足最小的情况，对m/gcd(n,m)取模就可以惹)

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int exgcd(int a,int b,int& x,int& y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x,y,n,m,vx,vy;
  cin>>n>>m>>x>>y>>vx>>vy;
  //预处理
  if(vx==0)
  {
    if(x==0||x==n)
    {
        if(vy==1)cout<<x<<" "<<m<<endl;
        else cout<<x<<" "<<0<<endl;
    }
    else cout<<-1<<endl;
    return 0;
  }
  if(vy==0)
  {
    if(y==0||y==m)
    {
        if(vx==1)cout<<n<<" "<<y<<endl;
        else cout<<0<<" "<<y<<endl;
    }
    else cout<<-1<<endl;
    return 0;
  }
  //确定反射位置
  bool fx=false,fy=false;
  int ansx,ansy;
  if(vx==-1)x=n-x,fx=true;
  if(vy==-1)y=m-y,fy=true;
  int a,b;
  int g=exgcd(n,m,a,b);
  if((x-y)%g!=0){
    cout<<-1<<endl;
    return 0;
  }
  int mul=(x-y)/g;
  a*=mul,b*=mul;
  int _a,_b;
  int _m=m/g,_n=n/g;
  _a=(a%_m+_m+_m-1)%_m+1;//很重要的写法
  _b=-(((x-y)-_a*n)/m);
  ansx=(_a&1)==1?n:0;
  ansy=(_b&1)==1?m:0;
  if(fx)ansx=n-ansx;
  if(fy)ansy=m-ansy;
  cout<<ansx<<" "<<ansy<<endl;
  return 0;
}