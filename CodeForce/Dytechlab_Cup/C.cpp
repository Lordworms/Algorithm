/*
思考以下几种情况
我们假设中心点在黑色块，非中心点在白色块
1.假设中心点在四个角上
    那么只能够到达四条边上的点，判断目标点是不是在四条边上就好了
2.假设目标点是黑色块
    当且仅当目标点和中心点的奇偶性相同的时候才可以到达
    这个时候有个技巧,同花色的点满足
    (Xc+Yc)%2==(x+y)%2具体原因自己想想就可以了
3.假设目标点是白色块
    我们总可以到达目标点，因为可以通过中心点让两个非中心点到达任何一条斜边
细看怎么求中心点的
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve()
{
    int n;
    cin>>n;
    int r1,r2,r3,c1,c2,c3;
    cin>>r1>>c1>>r2>>c2>>r3>>c3;
    int x,y;
    cin>>x>>y;
    int r0=r1==r2?r1:r3;
    int c0=c1==c2?c1:c3;
    int dir[4][2]={{1,1},{1,n},{n,1},{n,n}};
    //四个角的情况
    for(int i=0;i<4;++i)
    {
        int dx=dir[i][0],dy=dir[i][1];
        if(r0==dx&&c0==dy)
        {
            cout<<((x==dx||y==dy)?"YES":"NO")<<endl;
            return;
        }
    }
    //和中心点相同颜色的情况
    if((r0+c0)%2==(x+y)%2)
    {
        if(r0%2==x%2||c0%2==y%2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl; 
    }
    //和中心点颜色不同的情况
    else
    {
        cout<<"YES"<<endl;        
    }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--)
  {
   solve();
  }
  return 0;
}