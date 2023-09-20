#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = (1 << 8);
ll ipToLL(string s) {
  ll ans = 0;
  vector<int> seg;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') {
      seg.push_back(ans);
      ans = 0;
    } else {
      ans = ans * 10 + s[i] - '0';
      if (i == s.size() - 1) seg.push_back(ans);
    }
  }
  ans = 0;
  for (auto& s : seg) {
    ans = (ans << 8) + s;
  }
  return ans;
}
int cntZero(ll x) {
  int cnt = 0, i = 0;
  if (x == 0) {
    return 0;
  }
  while (((x >> i) & 1) == 0) {
    ++i, ++cnt;
  }
  return cnt;
}
string ipToString(ll x, int range) {
  string ip;
  vector<int> num;
  while (x) {
    num.push_back(x % M);
    x >>= 8;
  }
  while (num.size() < 4) {
    num.push_back(0);
  }
  ip = to_string(num[3]) + '.' + to_string(num[2]) + '.' + to_string(num[1]) + '.' +
       to_string(num[0]) + "/" + to_string(range);
  return ip;
}
void solve(string iip, int n) {
  vector<string> ans;
  auto orig = ipToLL(iip);
  while (n) {
    int zero = cntZero(orig);
    long numOfIp = 1, mask = 0;
    while (numOfIp < n && mask < zero) {
      numOfIp <<= 1, ++mask;
    }
    if (numOfIp > n) {
      --mask;
      numOfIp >>= 1;
    }
    ans.push_back(ipToString(orig, 32 - mask));
    n -= numOfIp;
    orig += numOfIp;
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " \n"[i == ans.size() - 1];
  }
}
int main() {
  solve("255.0.0.7", 10);
  return 0;
}