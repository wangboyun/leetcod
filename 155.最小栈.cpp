/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-08-23 10:42:25
 */
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <stack>
#include <utility>

using namespace std;
// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        if(sta.empty()){
            sta.push(make_pair(val, val));
        }else {
            sta.push(make_pair(val, min(val,sta.top().second)));
        }
    }
    
    void pop() {
        sta.pop();
    }
    
    int top() {
        return sta.top().first;
    }
    
    int getMin() {
        return sta.top().second;
    }

private:
    stack<pair<int , int>> sta;
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

