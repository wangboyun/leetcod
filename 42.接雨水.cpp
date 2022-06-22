/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

/// 动态规划解决此问题

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    /// 单调栈做
    int trap(vector<int>& height) {
        stack<int> st;
        st.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); ++i){
            while(!st.empty() && height[i] > height[st.top()]){
                int mid = st.top();
                st.pop();
                if(!st.empty()){
                    int h = min(height[i], height[st.top()]) - height[mid];
                    int w = i - st.top() - 1;
                    sum += h * w;
                }
            }
            st.push(i);
        }
        return sum;
    }
};
// @lc code=end

///dp 动态规划做的
int trap(vector<int>& height) {
        vector<int> leftmax(height.size() , 0);
        vector<int> rightmax(height.size(), 0);
        int size = height.size();
        int sum = 0;
        /// 遍历数组找到每一个位置上左边和右边最大值存入对应数组里面
        leftmax[0] = height[0];
        for(int i = 1; i < size; ++i){
            leftmax[i] = max(height[i] , leftmax[i - 1]);
        }

        rightmax[size - 1] = height[size - 1];
        for(int i = size - 2 ; i >= 0 ; --i){
            rightmax[i] = max(height[i] , rightmax[i + 1]);
        }

        for(int i = 0 ; i < height.size() ; ++i){
            int count = min(leftmax[i] , rightmax[i]) - height[i];
            if(count > 0){
                sum += count;
            }
        }
        return sum;
    }