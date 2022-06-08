#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
    // lambda 表达式作为 Campare，当返回 true 时，left 先进入，后输出，即在优先级队列（堆）的下方
auto cmp = [](pair<int, int> left, pair<int, int> right) -> bool { return left.second < right.second; };
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

   return 0;
}
