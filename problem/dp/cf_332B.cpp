#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
void solve(){
	int a,b;
    cin>>a>>b;
	if(gcd(a, b) == 1){
		cout << 1 << endl;
		cout << a << ' ' << b << endl;
	}
	else {
		cout << 2 << endl;
		cout << 1 << ' ' << b - 1 << endl;
		cout << a << ' ' << b << endl;
	}
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef LOCAL
  freopen("/Users/xiangyanxin/code/Algorithom/in.txt","r",stdin);
  freopen("/Users/xiangyanxin/code/Algorithom/out.txt","w",stdout);
  #endif
  int T;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}