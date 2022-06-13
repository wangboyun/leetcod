/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-01 21:34:02
 */
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>
using namespace std;

// @lc code=start
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        int stasize = sta.size();
        for(int i = 0 ; i < stasize; ++i ){
            s.push(sta.top());
            sta.pop();
        }
        s.push(x);
        int ssize = s.size();
        for(int i = 0 ; i < ssize ; ++i){
            sta.push(s.top());
            s.pop();
        }

    }
    
    int pop() {
        int tem = sta.top();
        sta.pop();
        return tem;
    }
    
    int peek() {
        return sta.top();
    }
    
    bool empty() {
        return sta.empty();
    }
private:
    stack<int> sta;
    stack<int> s;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

