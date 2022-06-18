/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    void backtracking(vector<int>& candidates, int target, int startindex,int sum ,vector<int>& ve, vector<vector<int>>& res){
        if(sum > target)    return;
        else if(sum == target) {
            res.emplace_back(ve);
            return;
        }

        for(int i = startindex ; i < candidates.size() && sum + candidates[i] <= target ; ++i){
            sum += candidates[i];
            ve.emplace_back(candidates[i]);
            backtracking(candidates, target, i, sum, ve, res);
            ve.pop_back();
            sum -= candidates[i];
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ve;
        vector<vector<int>> res;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, sum, ve, res);
        return res;
    }
};
// @lc code=end

