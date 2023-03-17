#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int cnt;
int trie[N][2];
int f[N][2];
int newNode() {
    ++cnt;
    trie[cnt][0] = trie[cnt][1] = 0;
    f[cnt][0] = f[cnt][1] = 0;
    return cnt;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}