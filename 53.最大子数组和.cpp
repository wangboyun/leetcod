/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = nums[0];
        for(int i = 0 ; i < nums.size() ; ++i){
            if(sum > 0){
                sum += nums[i];
            }else {
                sum = nums[i];
            }
            ans = ::max(sum , ans);
        }
        return ans;
    }
};
// @lc code=end

