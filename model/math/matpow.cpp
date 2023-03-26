#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
const int MOD=1e9+7;
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
int main(){
  
  return 0;
}