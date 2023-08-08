#include <bits/stdc++.h>
using namespace std;

void print(int next[], int n) {
  for (int i = 0; i < n; ++i) {
    cout << next[i] << " ";
  }
}
void get_next(vector<int>& nxt, const string& s) {
  int j, m = s.size();  // get the size of input string
  for (int i = 1; i < m; ++i) {
    j = nxt[i - 1];  // we starts from the logest prefix of previous position
    while (j != -1 && s[j + 1] != s[i]) {  // when we could not get a match, we
                                           // jump to the next of current j
      j = nxt[j];
    }
    if (s[j + 1] == s[i]) {
      nxt[i] = j + 1;
    }
  }
}
bool kmp(string ori, string pat) {
  int n = ori.size(), m = pat.size();
  vector<int> nxt(m, -1);
  get_next(nxt, pat);
  int ppos = 0, spos = 0;
  while (spos < ori.size()) {
    if (ori[spos] == pat[ppos])
      ++ppos, ++spos;
    else if (ppos == pat.size())
      return true;
    else if (ppos) {
      ppos = nxt[ppos] == -1 ? 0 : nxt[ppos];
    } else {
      spos++;
    }
  }
  return false;
}
int nxt[1000005];
void init_next(string s) {
  int l = s.size();
  s = ' ' + s;          // starts from 1
  nxt[0] = nxt[1] = 0;  // 初始化next数组
  int j = 0;            // 下标
  for (int i = 2; i <= l; i++) {
    while (j > 0 && s[i] != s[j + 1])
      j = nxt[j];  // not match, jump to next[j]
    if (s[i] == s[j + 1]) j++;  // matched ++j
    nxt[i] = j;                 // update the next array
  }
}
int main() {
  cout << kmp("a", "abcabcdabc");
  return 0;
}