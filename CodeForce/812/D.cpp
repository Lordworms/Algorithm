#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve()
{
  auto query=[&](int x,int y)
  {
    cout<<"? "<<x<<" "<<y<<'\n';
    int res;
    cin>>res;
    cout.flush();
    return res;
  };
  auto report=[&](int x)
  {
    cout<<"! "<<x<<'\n';
    cout.flush();
  };
  int n;cin>>n;
  vector<int>arr(1<<n);
  for(int i=0;i<(1<<n);++i)
  {
    arr[i]=i+1;
  }
  while(arr.size())
  {
    vector<int>tmp;
    if(arr.size()==1)
    {
        report(arr[0]);
        return;
    }
    else if(arr.size()==2)
    {
        if(query(arr[0],arr[1])==1)
        {
            report(arr[0]);
            return;
        }
        else
        {
            report(arr[1]);
            return;
        }
    }
    else
    {
        for(int i=0;i<arr.size();i+=4)
        {
            int r1=query(arr[i],arr[i+2]),r2;
            if(r1==1)
            {
                r2=query(arr[i],arr[i+3]);
                if(r2==1)
                {
                    tmp.push_back(arr[i]);
                }
                else
                {
                    tmp.push_back(arr[i+3]);
                }
            }
            else if(r1==2)
            {
                r2=query(arr[i+1],arr[i+2]);
                if(r2==1)
                {
                    tmp.push_back(arr[i+1]);
                }
                else
                {
                    tmp.push_back(arr[i+2]);
                }
            }
            else
            {
                r2=query(arr[i+1],arr[i+3]);
                if(r2==1)
                {
                    tmp.push_back(arr[i+1]);
                }
                else
                {
                    tmp.push_back(arr[i+3]);
                }
            }
        }
    }
    swap(arr,tmp);
  }
  return;
}
int main()
{ 
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}