#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const int MAXN=1e5+10;
int tree[MAXN<<2][26];
int is_leaf[MAXN<<2];
int cnt;
int win[MAXN<<2],lose[MAXN<<2];
void add(string s){
    int cur=0;
    for(int i=0;i<s.size();++i){
        is_leaf[cur]=0;
        int x=s[i]-'a';
        if(!tree[cur][x]){
            tree[cur][x]=++cnt;
        }
        cur=tree[cur][x];
    }
}
int dfs_win(int x){
    if(is_leaf[x]){
        return win[x]=0;
    }
    for(int i=0;i<26;++i){
        if(tree[x][i]&&!dfs_win(tree[x][i])){//有一个后继节点是没有必胜策略的，那么可以走到这个节点导致必胜
            return win[x]=1;
        }
    }
    return win[x]=0;
}
int dfs_lose(int x){
    if(is_leaf[x]){
        return lose[x]=1;
    }
    for(int i=0;i<26;++i){
        if(tree[x][i]&&!dfs_lose(tree[x][i])){//有一个节点没有必败策略，那么我们可以走到这个节点导致当前必败
            return lose[x]=1;
        }
    }
    return lose[x]=0;
}
void solve(){
  ll n,k;
  cin>>n>>k;
  memset(is_leaf,1,sizeof(is_leaf));
  for(int i=0;i<n;++i){
    string s;
    cin>>s;
    add(s);
  }
  dfs_win(0);
  dfs_lose(0);
  if(win[0]){
    if(lose[0]){
        cout<<"First\n";
    }else{
        cout<<(k&1?"First":"Second")<<'\n';
    }
  }else{
    cout<<"Second\n";
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