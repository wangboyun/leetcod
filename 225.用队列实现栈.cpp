/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-01 19:50:00
 */
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>
using namespace std;

// @lc code=start
class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        int quesize = que.size();
        for(int i = 0 ; i < quesize; ++i){
            q.push(que.front());
            que.pop();
        }
        que.push(x);
        int qsize = q.size();
        for(int i = 0 ; i < qsize ; ++i){
            que.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int tem = que.front();
        que.pop();
        return tem;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
private: 
    queue<int> que;
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

