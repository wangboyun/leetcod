/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int len = nums.size();
        vector<int> ans(len, -1);
        for(int i = 0; i < 2 * len ; ++i){
            while(!st.empty() && nums[i % len] > nums[st.top()]){
                ans[st.top()] = nums[i % len];
                st.pop();
            }
            st.push(i % len);
        }
        return ans;
    }
};
// @lc code=end

