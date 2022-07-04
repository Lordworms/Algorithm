/*
    字典树的模版，
*/
#include <bits/stdc++.h>
using namespace std;
static const int MAXN=1e6;
struct trie{
    int nxt[MAXN][26],cnt;
    bool exist[MAXN];
    void insert(string s)
    {
        int p=0;
        for(int i=0;i<s.size();++i)
        {
            int c=s[i]-'a';
            if(!nxt[p][c])nxt[p][c]=++cnt;
            p=nxt[p][c];
        }
        exist[p]=1;
    }
    bool find(string s)
    {
        int p=0;
        for(int i=0;i<s.size();++i)
        {
            int c=s[i]-'a';
            if(!nxt[p][c])return false;
            p=nxt[p][c];
        }
        return exist[p];
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}