/*
    AC自动机，说白了就是KMP+TRIE树
    1.AC 自动机的失配指针指向当前状态的最长后缀状态即可。
    其余详情看代码
*/
#include <bits/stdc++.h>
using namespace std;
namespace AC {
const int MAXN = 1e6 + 100;
int n;
int tr[MAXN][26], cnt;  // tr可以理解为trans,即从u状态转移到i状态的转移函数
int e[MAXN], fail[MAXN];  // e为end
int idx[MAXN], val[MAXN];  // idx[u]为以u结尾的字符串在原字符串数组里的编号
int c[MAXN];  // 记录第i个z字符串出现的次数
void init() {
  memset(c, 0, sizeof(c));
  memset(tr, 0, sizeof(tr));
  memset(e, 0, sizeof(e));
  memset(fail, 0, sizeof(fail));
  memset(val, 0, sizeof(val));
  memset(idx, 0, sizeof(idx));
  cnt = 0;
}
void insert(string s, int id) {
  int u = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++cnt;
    u = tr[u][s[i] - 'a'];
  }
  e[u]++;
  idx[u] = id;
}
queue<int> q;
void build() {
  for (int i = 0; i < 26; ++i)
    if (tr[0][i]) q.push(tr[0][i]);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < 26; ++i) {
      if (tr[u][i])  // 后边还有
      {
        fail[tr[u][i]] = tr[fail[u]][i];  //?
        q.push(tr[u][i]);
      } else {
        tr[u][i] = tr
            [fail[u]]
            [i];  // 为了让之后的操作能够顺利到达，如果当前匹配不了了，姐直接跳到fail对应的下一个值里去
      }
    }
  }
}
int query_1(string s)  // 获得多少个模式串在文本串中出现
{
  int u = 0, res = 0;
  for (int i = 0; i < s.size(); ++i) {
    u = tr[u][s[i] - 'a'];
    for (int j = u; j && e[j] != -1; j = fail[j]) {
      res += e[j], e[j] = -1;
    }
  }
  return res;
}
int query_2(string s)  // 获得哪个模式串在文本串中出现的最多
{
  int u = 0, res = 0;
  for (int i = 0; i < s.size(); ++i) {
    u = tr[u][s[i] - 'a'];
    for (int j = u; j; j = fail[j]) val[j]++;
  }
  for (int i = 0; i <= cnt; ++i)
    if (idx[i]) res = max(res, val[i]), c[idx[i]] = val[i];
  return res;
}
}  // namespace AC
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (1) {
    AC::init();
    cin >> n;
    if (!n) break;
    string s;
    vector<string> st(n);
    for (int i = 0; i < n; ++i) cin >> st[i], AC::insert(st[i], i + 1);
    AC::build();
    cin >> s;
    int id = AC::query_2(s);
    for (int i = 1; i <= n; ++i)
      if (AC::c[i] == id) cout << st[i - 1] << endl;
  }
  return 0;
}