/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <vector>
#include <stack>

using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int result = 0;
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        st.push(0);
        for(int i = 1; i < heights.size() ; ++i){
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                if(!st.empty()){
                    int h = heights[mid];
                    int w = i - st.top() - 1;
                    int sum = h * w;
                    result = max(result, sum);
                }
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

