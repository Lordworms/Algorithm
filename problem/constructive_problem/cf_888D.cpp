#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[]={0,0,1,2,9};
ll n;
ll C(int y)
{
	ll rz=1;
	for(int i=n;i>n-y;i--)
	rz*=i;
	for(int i=1;i<=y;i++)
	rz/=i;
	return rz;
}
int main()
{
	int k;
	ll count=1;
	cin>>n>>k;
	for(int i=2;i<=k;i++)
	count+=C(i)*ans[i];
	cout<<count;
	return 0;
}
