/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    /// 同树层去除(used[i - 1] == false)，没插入一个节点都得增加一个

    void backtracking(vector<int>& nums , int startindex , bool used[], vector<int>& ve , vector<vector<int>>& res){
        if(startindex > nums.size() - 1){
            return;
        }
        for(int i = startindex ; i < nums.size() ; ++i){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            used[i] = true;
            ve.emplace_back(nums[i]);
            res.emplace_back(ve);
            backtracking(nums, i + 1, used, ve, res);
            ve.pop_back();
            used[i] = false;
        }
        return;
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        bool used[10] = {false}; 
        vector<int> ve  ;
        vector<vector<int>> res;
        res.emplace_back(ve);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used, ve, res);
        return res;
    }
};
// @lc code=end

