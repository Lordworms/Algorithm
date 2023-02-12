/*
    构造方式很简单，两两构造，最终的序列应该为
    ()()()()(((())))
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
using pii=pair<int,int>;
void solve()
{
  int n,k;cin>>n>>k;
  string s;
  cin>>s;
  vector<pii>ops;
  auto find=[&](int st,char c)
  {
    for(int i=st;i<s.size();++i)
    {
        if(s[i]==c)
        {
            return i;
        }
    }
    return -1;
  };
  auto rev=[&](string& s,int st,int end)
  {
    reverse(s.begin()+st,s.begin()+end+1);
  };
  int st=-2;
  for(int i=0;i<k;++i)
  {
    st+=2;
    if(s[st]=='(')
    {
        if(s[st+1]==')')continue;
        int id=find(st+2,')');
        rev(s,st+1,id);
        ops.push_back({st+1,id});
    }
    else
    {
        int id=find(st+1,'(');
        rev(s,st,id);
        ops.push_back({st,id});
        if(s[st+1]==')')continue;
        id=find(st+2,')');
        rev(s,st+1,id);
        ops.push_back({st+1,id});
    }
  }
  for(int i=2*k-1;i<s.size();++i)
  {
    if(s[i]=='(')continue;
    int id=find(i+1,'(');
    if(id==-1)break;
    rev(s,i,id);
    ops.push_back({i,id});
  }
  cout<<ops.size()<<'\n';
  for(auto& k:ops)
  {
    cout<<k.first+1<<' '<<k.second+1<<'\n';
  }
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
  int T;
  cin>>T;
  while(T--)
  {
    solve();
  }
  return 0;
}