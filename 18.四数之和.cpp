/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-01 20:33:42
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(auto i = nums.begin() ; i < nums.end() - 3 ; ++i){
            vector<int> temp = nums;
            int t = target - *i;
            temp.erase(i);
            for(int j = 0 ; j < temp.size() - 2 ; ++j){
                int left = j + 1; int right  = nums.size() - 1;
                while (left < right) {
                    if(t - nums[j] == nums[left] + nums[right]){
                        ans.emplace_back(vector<int> {*i ,j , left , right});
                    }else if(t - nums[j] < nums[left] + nums[right]){
                        ++left;
                    }else{
                        --right;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

