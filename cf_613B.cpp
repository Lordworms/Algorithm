#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long LL;
struct inst {
	long long  x;
	long long  id;
};
inst ax[100100];
long long  mam[100100];
pair<long long, pair<long long, long long>>ans;
long long  cmp(inst a, inst b) {
	return a.x < b.x;
}
long long  cmp2(inst a, inst b) {
	return a.id < b.id;
}
int  main(void) {
	long long  n, a, ma, mi, k;
	scanf("%lld%lld%lld%lld%lld", &n, &a, &ma, &mi, &k);
	for (long long  i = 1; i <= n; i++) {
		scanf("%lld", &ax[i].x);
		ax[i].id = i;
	}
	sort(ax+1, ax+1 + n,cmp);
	mam[0] = 0;
	for (long long  i = 1; i <= n; i++) {
		mam[i] = mam[i - 1] +ax[i].x;
	}
	long long p = n;
	for (int i = 0; i <=n; i++) {
		long long dd = k -i*a+mam[n]-mam[n-i];
		if (dd < 0) {
			break;
		}
		p = min(p, n-i);
		while (p>1 && dd < p*ax[p].x-mam[p]) {
			p--;
		}
		dd -= p*ax[p].x - mam[p];
		long long k = min(a, i == n ? a : (ax[p].x + dd / p));
		ans = max(ans, { i*ma + k*mi,{i,k} });
	}
	printf("%lld\n", ans.first);
	for (int i = 0; i < ans.second.first; i++) {
		ax[n-i].x = a;
	}
	for (int i = 1; i <= n; i++) {
		ax[i].x = max(ax[i].x, ans.second.second);
	}
	sort(ax+1, ax+1 + n, cmp2);	
	for (long long  i = 1; i <= n; i++) {
		printf("%lld ", ax[i].x);
	}
	printf("\n");
 
	return 0;
}