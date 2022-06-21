/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    /// 使用单调栈解决
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;      /// 单调栈 存下标
        vector<int> ans(temperatures.size() , 0);
        for(int i = 0 ; i < temperatures.size(); ++i){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            } 
            st.push(i);  
        }
        return ans;
    }
};
// @lc code=end

