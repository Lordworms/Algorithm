/*
    1.预处理出每个点向上延伸可以到哪里
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
  int n,m;
  cin>>n>>m;
  vector<string>s(n);
  for(int i=0;i<n;++i)
  {
    cin>>s[i];
  }
  int ans=0;
  vector<vector<int>>up(n,vector<int>(m,-1)),upm(up);//upm不使用m可以到达的最上，up使用一个m可以到达的最上
  vector<vector<int>>d(n,vector<int>(m,n)),dm(d);
  for(int i=1;i<n;++i)
  {
    up[i]=up[i-1];
    upm[i]=upm[i-1];
    for(int j=0;j<m;++j)
    {
        if(s[i-1][j]=='#')
        {
            up[i][j]=upm[i][j]=i-1;//直接赋值为i-1，#不能通过
        }
        if(s[i-1][j]=='m')
        {
            upm[i][j]=i-1;//upm直接赋值为i-1
            up[i][j]=std::max(upm[i-1][j],up[i][j]);//up需要取直接跳过上面那个m的值
        }
    }
  }
  for(int i=n-2;i>=0;--i)
  {
    d[i]=d[i+1];
    dm[i]=dm[i+1];
    for(int j=0;j<m;++j)
    {
        if(s[i+1][j]=='#')
        {
            d[i][j]=dm[i][j]=i+1;
        }
        if(s[i+1][j]=='m')
        {
            dm[i][j]=i+1;
            d[i][j]=std::min(dm[i+1][j],d[i][j]);
        }
    }
  }
  auto update=[&](int len,int* a)
  {
    int upp=std::min(a[0],a[1])-1;
    int dpp=std::min(a[2],a[3])-1;
    if(upp&&dpp)
    {
        ans=max(ans,2*(upp+dpp)+len);
    }
  };
  //枚举水平线
  for(int i=0;i<n;++i)
  {
    for(int l=0;l<m;++l)
    {
        int cnt=0;
        for(int r=l;r<m;++r)
        {
            if(s[i][r]=='#')break;
            if(s[i][r]=='m')cnt++;
            if(cnt>1)break;
            if(r-l<2)continue;
            //a represent the path without m;
            int a[4]={i-upm[i][l],i-upm[i][r],dm[i][l]-i,dm[i][r]-i};
            int b[4]={i-up[i][l],i-up[i][r],d[i][l]-i,d[i][r]-i};
            update(r-l+1,a);
            if(cnt==0)
            {
                for(int j=0;j<4;++j)
                {
                    std::swap(a[j],b[j]);
                    update(r-l+1,a);
                    std::swap(a[j],b[j]);
                }
            }
        }
    }
  }
  std::cout<<ans<<'\n';
  return;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  solve();
  return 0;
}