/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans = {0};
        vector<int> rt;
        ans.resize(nums.size());
        for(int i = 0 ; i < nums.size() ; ++i){
            if(ans[nums[i] - 1] == 0)
                ans[nums[i] - 1] = nums[i];
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if(ans[i] == 0){
                rt.emplace_back(i + 1);
            }
        }
        return rt;
    }
};
// @lc code=end

