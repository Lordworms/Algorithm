/*
    给你一个数组，找到一个子数组，使其去掉一个递减子序列后是一个递增子序列
    dp means the element i is in a increase subsequence and the greatest number in this subsequence
    dp[i]:[i,n]= +00 (only if this increase subsequence is empty)
                 -00 (only if the array is impossible)
                 v   (greatest number in the subsequence)
    pd[i] got the same meaning with dp[i] but it indicates the smallest number
    a array is not decinc only if dp[i]= -00 and pd[i]=+00
    

*/
# include <bits/stdc++.h>
 
using namespace std;
 
const int N = 10;
 
int n, a[N], dp[N], pd[N], f[N];
long long ans;
 
inline void upd(int i){//[i,n]
	if (n < i)
		return;
	int inc = 0, dec = n + 1;//inc表示递增最大，dec表示递减最小
	if (pd[i - 1] < a[i])//
		inc = max(inc, a[i - 1]);
	if (a[i - 1] < a[i])
		inc = max(inc, dp[i - 1]);
	if (a[i] < dp[i - 1])
		dec = min(dec, a[i - 1]);
	if (a[i] < a[i - 1])
		dec = min(dec, pd[i - 1]);
	if (inc == dp[i] && dec == pd[i])
		return;
	dp[i] = inc, pd[i] = dec;
	f[i] = 0;
	if (dec <= n || inc){
		upd(i + 1);
		f[i] = f[i + 1] + 1;
	}
	return;
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
    memset(dp,-1,sizeof(dp));
    memset(pd,-1,sizeof(pd));
	for (int i = n; 1 <= i; -- i){//
		dp[i] = n + 1;
		pd[i] = 0;
		upd(i + 1);
		f[i] = f[i + 1] + 1;
		ans += f[i];
	}
	cout << ans << '\n';
 
	return 0;
}