/*
题意：
    给你一个无向图，无向图由整数 n  ，表示图中节点的数目，和 edges 组成，其中 edges[i] = [ui, vi] 表示 ui 和 vi 之间有一条无向边。同时给你一个代表查询的整数数组 queries 。

第 j 个查询的答案是满足如下条件的点对 (a, b) 的数目：
    a < b
    cnt 是与 a 或者 b 相连的边的数目，且 cnt 严格大于 queries[j] 。
请你返回一个数组 answers ，其中 answers.length == queries.length 且 answers[j] 是第 j 个查询的答案。
请注意，图中可能会有 重复边 。
题解：
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
            
    }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}