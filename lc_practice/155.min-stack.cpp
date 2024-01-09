/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MinStack {
private:
   stack<int> s, m; 
public:
    MinStack() {
      m.push(INT_MAX);  
    }
    
    void push(int val) {
      s.push(val);
      m.push(min(m.top(), val));   
    }
    
    void pop() {
      s.pop();
      m.pop();
    }
    
    int top() {
      return s.top();
    }
    
    int getMin() {
      return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

