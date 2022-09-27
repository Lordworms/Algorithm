#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> f, c, d;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    void U(int x, int y)
    {
        x = F(x);
        y = F(y);
        if (x == y)
        {
            return;
        }
        f[x] = y;
        c[y] += c[x];
    }
    int numberOfGoodPaths(vector<int>& v, vector<vector<int>>& e) {
        int n = v.size();
        f.resize(n);
        c.resize(n);
        d.resize(n);
        vector<vector<int> > a;
        a.resize(n);
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][0]].push_back(e[i][1]);
            a[e[i][1]].push_back(e[i][0]);
        }
        map<int, vector<int> > g;
        for (int i = 0; i < n; i++)
        {
            g[v[i]].push_back(i);
            f[i] = i;
        }
        long long ans = 0;
        for (auto i : g)
        {
            for (int j : i.second)
            {
                c[j] = 1;
                for (int k : a[j])
                {
                    if (c[k] > 0)
                    {
                        U(j, k);
                    }
                }
            }
            for (int j : i.second)
            {
                d[F(j)] = 0;
            }
            for (int j : i.second)
            {
                ans += ++d[F(j)];
            }
        }
        return ans;
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}