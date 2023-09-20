#include <bits/stdc++.h>
using namespace std;
class RangeModule {
private:
    map<int, int> mp;
public:
    RangeModule() {

    }
    
    void addRange(int left, int right) {
      int l = left, r = right;
      auto p = mp.lower_bound(left);
      while (p != mp.end() && p->second <= right) {
        l = min(l, p->second);
        r = max(r, p->first);
        auto tmp = p;
        p++;
        mp.erase(tmp->first);
      }
      mp[r] = l;
    }
    
    bool queryRange(int left, int right) {
      auto p = mp.lower_bound(left);
      if (p == mp.end()) return false;
      return p->second <= left && p->first >= right;    
    }
    
    void removeRange(int left, int right) {
      auto p = mp.lower_bound(left + 1);
      while (p != mp.end() && p->second <= right) {
        // left has free space
        if (p->second < left) {
          mp[left] = p->second;    
        }
        if(p->first > right) { // right has free space
          mp[p->first] = right;
          break;
        } else {
          auto tmp = p;
          p++;
          mp.erase(tmp->first);
        }
      }
    }
};

int main(){
  map<int, int> mp;
  return 0;
}