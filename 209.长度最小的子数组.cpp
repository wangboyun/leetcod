/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int start = 0 ; int end = 0;
        int sum = 0; int result = len + 1;
        for(int end = 0 ; end < len; ++end){
            sum += nums[end];
            while(sum >= target){
                result = min(result, end - start + 1);
                sum -= nums[start++];
            }
        }
        return result == len + 1 ? 0 : result;
    }
};
// @lc code=end

