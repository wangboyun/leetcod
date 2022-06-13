/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;

///双指针法
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int windSum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; ++i){   
            int left = i + 1; int right = nums.size() - 1;
            while(left < right){
                int threeSum = nums[i] + nums[left] + nums[right];
                /// if threeSum closest than windSum change
                if (abs(threeSum - target) < abs(windSum - target)) {
                    windSum = threeSum;
                }
                if(threeSum < target){
                    ++left;
                }else if(threeSum > target){
                    --right;
                }else {
                    return target;
                }
            } 
        }
        return windSum;
    }
};
// @lc code=end

