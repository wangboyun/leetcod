/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        stack<char> stack;
        stack.push(s[0]);
        for(int i = 1 ; i < len ; i++){
            if(stack.empty()){
                stack.push(s[i]);
                continue;
            }
            if( s[i] - stack.top()  == 1 || s[i] - stack.top() == 2){
                stack.pop();
            }
            else {
                stack.push(s[i]);
            }
        }
        if(stack.empty())
            return true;
        else
            return false;

    }
};
// @lc code=end

