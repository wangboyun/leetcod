
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <vector>
#include <deque>
using namespace std;

// @lc code=start
class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;  //单调递减队列
        for(int i = 0; i < nums.size(); i++){
            while(!q.empty() && nums[i] >= nums[q.back()]) 
                q.pop_back();
            q.push_back(i);
            if(q.back() - q.front() >= k) 
                q.pop_front(); //超出窗口容量，右移左边界
            
            if(i >= k - 1) 
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};
// @lc code=end

