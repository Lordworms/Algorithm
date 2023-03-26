#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll n,m;
struct Mat{
	ll mat[110][110];
	Mat(){};
	Mat operator*(Mat const &b)const
	{
		Mat res;
		memset(res.mat,0,sizeof(res.mat));
		for(int k=0;k<m;++k)
		   for(int i=0;i<m;++i)
		       for(int j=0;j<m;++j)
		          res.mat[i][j]=(res.mat[i][j]+(this->mat[i][k]*b.mat[k][j]))%MOD;
		return res;    
	}
};
Mat mat_pow(Mat A,ll k){
	Mat res;
	memset(res.mat,0,sizeof(res.mat));
    for(int i=0;i<m;++i)
        res.mat[i][i]=1;
    while(k>0)
    {
    	if(k&1)res=res*A;
    	A=A*A;
    	k=k>>1;
	}
	return res;
}
void solve(){
  cin>>n>>m;
  if(n<m){
    cout<<1<<'\n';
    return;
  }
  Mat base,A;
  A.mat[0][0]=A.mat[0][m-1]=1;
  for(int i=1;i<m;++i)A.mat[i][i-1]=1;
  for(int i=0;i<m;++i)base.mat[i][0]=1;
  A=mat_pow(A,n-m+1);
  base=A*base;
  cout<<base.mat[0][0]<<'\n';
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