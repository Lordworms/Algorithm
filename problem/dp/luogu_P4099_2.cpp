/*
    dp[i][j]表示点i在其子树内排名为j的数
    则我们对于两个不同的点x和y
    dp[x][i]和dp[y][k]
    设这两颗子树混合后x的排名为j
    则dp[x][j]+=C(j-1,i-1)*C(siz[x]+siz[y]-j,siz[x]-j)*dp[x][i]*dp[y][rank[y]>(j-i)]
    最后的dp[y][rank[y]>(j-i)]可以用前缀和来求
    最后得到答案

*/
#include <bits/stdc++.h>
using namespace std;
int T,n;
const int MAXN=1e3+10;
int dp[MAXN][MAXN];
int f[MAXN],head[MAXN];
int siz[MAXN];
int mod=1e9+7;
struct edge{
    int nxt,v,w;
}E[3*MAXN];
int cnt;
int C[MAXN][MAXN];
void add_edge(int u,int v,int w)
{
    E[++cnt]={head[u],v,w};
    head[u]=cnt;
}
void init()
{
    memset(dp,0,sizeof(dp));
    memset(f,0,sizeof(f));
    memset(head,0,sizeof(head));
    memset(siz,0,sizeof(siz));
    cnt=0;
}
void dfs(int x)
{
    dp[x][1]=siz[x]=1;
    for(int u=head[x];u;u=E[u].nxt)
    {
        int y=E[u].v,w=E[u].w;
        if(siz[y])continue;
        dfs(y);
        memcpy(f,dp[x],sizeof(f));
        memset(dp[x],0,sizeof(f));
        if(w)//x->y
        {
            for(int i=1;i<=siz[x];++i)
            {
                for(int j=i;j<=i+siz[y]-1;++j)//i<=j<=
                {
                    dp[x][j]+=1LL*C[j-1][i-1]*C[siz[x]+siz[y]-j][siz[x]-i]%mod*f[i]%mod*(dp[y][siz[y]]-dp[y][j-i]+mod)%mod;
                    dp[x][j]%=mod;
                }
            }
        }
        else
        {
            for(int i=1;i<=siz[x];++i)
            {
                for(int j=i+1;j<=i+siz[y];++j)
                {
                    dp[x][j]+=1LL*C[j-1][i-1]*C[siz[x]+siz[y]-j][siz[x]-i]%mod*f[i]%mod*dp[y][j-i]%mod;
                    dp[x][j]%=mod;
                }
            }
        }
        siz[x]+=siz[y];
    }
    for(int i=1;i<=n;++i)dp[x][i]=(dp[x][i-1]+dp[x][i])%mod;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>T;
  
  C[0][0]=1;// do not forget
	for(int i=1;i<MAXN;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
  
 /*
  for(int i=1;i<MAXN;++i)
  {
    C[i][0]=1;
    for(int j=1;j<i;++j)
    {
        C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    C[i][i]=1;
  }
  */
  int u,v;
  char c;
  while(T--)
  {
    init();
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        cin>>u>>c>>v;
        ++u,++v;
        add_edge(u,v,c=='<'),add_edge(v,u,c=='>'); 
    }
    dfs(1);
    cout<<(dp[1][n]+mod)%mod<<endl;
  }
  return 0;
}