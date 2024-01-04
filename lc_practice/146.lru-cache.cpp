/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
 private:
  unordered_map<int, list<pair<int, int>>::iterator> mp;
  list<pair<int, int>> lis;
  int cap;

 public:
  LRUCache(int cap) { this->cap = cap; }

  int get(int key) {
    if (mp.find(key) == mp.end()) {
      return -1;
    }
    int res = mp[key]->second;
    lis.erase(mp[key]);
    lis.push_back({key, res});
    mp[key] = (--lis.end());
    return res;
  }
  void put(int key, int value) {
    if (mp.find(key) == mp.end()) {
      if (mp.size() == cap) {
        mp.erase(mp.find(lis.front().first));
        lis.pop_front();
      }
    } else {
        lis.erase(mp[key]);
    }
    lis.push_back({key, value});
    mp[key] = (--lis.end());
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
// int main() {
//   LRUCache lru(2);
//   lru.put(1, 0);
//   lru.put(2, 2);
//   assert(lru.get(1) == 0);
//   lru.put(3, 3);
//   assert(lru.get(2) == 2);
//   lru.put(4, 4);
//   assert(lru.get(1) == -1);
//   assert(lru.get(3) == 3);
//   assert(lru.get(4) == 4);
// }