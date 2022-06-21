/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:

    int getIndex(int n, vector<int>& nums2){
        for(int i = 0 ; i < nums2.size(); ++i){
            if(nums2[i] == n){
                return i;
            }
        }
        return -1;
    }

    /// 从小到大一个单调栈
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> result(nums2.size(), -1);
        vector<int> ans;
        for(int i = 0 ; i < nums2.size(); ++i){
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0 ; i < nums1.size(); ++i){
            int index = getIndex(nums1[i] , nums2);
            if(result[index] != -1)
                ans.emplace_back(nums2[result[index]]);
            else{
                ans.emplace_back(-1);
            }
        }
        return ans;

    }
};
// @lc code=end

