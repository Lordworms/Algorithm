#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
void solve(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<string>sets(n+1);
  unordered_map<string,int>mp;
  vector<int>fa(2*n+1);
  for(int i=1;i<=n;++i){
    cin>>sets[i];
    mp[sets[i]]=i;
    fa[i]=i;
    fa[i+n]=i+n;
  }
  function<int(int)>find=[&](int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
  };
  for(int i=1;i<=m;++i){
    int t;
    string s1,s2;
    cin>>t>>s1>>s2;
    int u=mp[s1],v=mp[s2];
    switch (t)
    {
        case 1:{//same
            if(find(u)==find(v+n)){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                fa[find(v)]=find(u);
                fa[find(v+n)]=find(u+n);
            }
            break;
        }
        case 2:{//diff
            if(find(v)==find(u)){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                fa[find(v)]=find(u+n);
                fa[find(v+n)]=find(u);
            }
            break;
        }
        default:
            break;
    }
  }
  while(q--){
    string s1,s2;
    cin>>s1>>s2;
    int u=mp[s1],v=mp[s2];
    if(find(u)==find(v)){
        cout<<1<<'\n';
    }else if(find(u)==find(v+n)||find(v)==find(u+n)){
        cout<<2<<'\n';
    }else{
        cout<<3<<'\n';
    }
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T=1;
  while(T--){
    solve();
  }
  return 0;
}