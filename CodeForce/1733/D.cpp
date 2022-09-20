/*
    输入a，b两个串，首先确认一点，当a[i]^b[i]==1的时候，a[i]!=b[i]
    然后统计有多少个位置不相同
    我们有如下这几种情况
    1.cnt>2 那么直接cnt/2 *y即可
    2.cnt=2
        分以下几种情况来操作  
        1.xxab.... ...abxx
            此时答案为min(x,2*y)
        2.abx xab
            此时答案为x
        3.xabx..
            此时答案为min(x,3*y);
*/
#include <bits/stdc++.h>
using namespace std;
using i64=long long;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n,x,y;
  int T;
  cin>>T;
  
  while(T--)
  {
    cin>>n>>x>>y;
    vector<int>pos;
    vector<int>arr(n);
    char ch;
    for(int i=0;i<n;++i)
    {
        cin>>ch;
        arr[i]=ch-'0';
    }
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        cin>>ch;
        arr[i]^=(ch-'0');
        if(arr[i]){
            ++cnt;
            pos.push_back(i);
        }
    }
    if(cnt%2==1)
    {
        cout<<-1<<endl;
        continue;
    }
    if(cnt!=2||pos[0]+1<pos[1])
    {
        cout<<1LL*(cnt/2)*y<<endl;
    }
    else 
    {
        if(pos[0]>1||pos[1]<n-2)
        {
            cout<<min(x,2*y)<<endl;
        }
        else if(n>=4)
        {
            cout<<min(x,3LL*y)<<endl;
        }
        else
        {
            cout<<x<<endl;
        }
    }
  }
  return 0;
}