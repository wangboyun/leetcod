/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    // 子集就是每一步都得记录

    void backtracking(vector<int>& nums, int startindex,vector<int>& ve, vector<vector<int>>& res){
        if(startindex > nums.size() - 1){
            return ;
        }

        for(int i = startindex ; i < nums.size() ; ++i){
            ve.emplace_back(nums[i]);
            res.emplace_back(ve);
            backtracking(nums, i + 1, ve, res);
            ve.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ve; vector<vector<int>> res;
        res.emplace_back(ve);
        backtracking(nums, 0, ve, res);
        return res;
    }
};
// @lc code=end

