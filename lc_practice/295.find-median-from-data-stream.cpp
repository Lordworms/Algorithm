/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
private:
    multiset<int> st;
    multiset<int>::iterator l, r;
public:
    MedianFinder() {
      
    }
    
    void addNum(int num) {
      int n = st.size();
      st.insert(num);
      if (!n) {
        l = r = st.begin();
      } else if (n & 1) {
        if (*l > num) {
          --l;
        } else {
          ++r;
        }
      } else {
        if (*l < num && *r > num) {
          ++l;
          --r;
        } else if (*r <= num) {
          ++l;
        } else {
          --r;
          l = r;
        }
      }
    }
    
    double findMedian() {
      return (*l + *r) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

