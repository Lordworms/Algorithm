//ll dfs(ll pos,ll pmod,ll plcm,ll limit){//pos,前面的数对2520的mod，前面数的lcm，limit  
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const ll inf=0x3f3f3f3f;
const ll lcmm=2520;
ll dp[25][lcmm+10][50];//pos,pmod,id[plcm]
ll id[lcmm+10];//记录plcm的id 
ll a[25];
 
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
 
void init(){
	ll cnt=0;
	for(ll i=1;i<=lcmm;i++)
		if(lcmm%i==0)
			id[i]=cnt++;//离散化  记录id 
	mem(dp,-1);
}
 
ll dfs(ll pos,ll pmod,ll plcm,ll limit){//pos,前面的数对2520的mod，前面数的lcm，limit 
	if(pos<0)return pmod%plcm==0;
	if(!limit&&~dp[pos][pmod][id[plcm]])
		return dp[pos][pmod][id[plcm]];
	ll res=0;
	ll up=limit?a[pos]:9;
	for(ll i=0;i<=up;i++){
		ll nmod=(pmod*10+i)%lcmm;//前面累积的mod 
		ll nlcm=plcm;//注意非零的时候 
		if(i) nlcm=lcm(plcm,i);//新的 lcm 
		
		res+=dfs(pos-1,nmod,nlcm,i==up&&limit);
        if(res>10)cout<<res<<endl;
	}
	if(!limit) dp[pos][pmod][id[plcm]]=res;
	return res;
}
 
ll solve(ll x){
	ll cnt=0;
	while(x){
		a[cnt++]=x%10;
		x/=10;
	}
	return dfs(cnt-1,0,1,1);
}
 
int main()
{
	ll t;
	cin>>t;
	init();//又忘了写了。。。
	while(t--){
		ll x,y;
		cin>>x>>y;
		ll res=solve(y)-solve(x-1);	
		cout<<res<<endl;
	}
	return 0;
}