/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    void backtracking(vector<int>& nums , int k, int n, int startindex, int sum ,vector<int>& ve, vector<vector<int>>& res){
        if(ve.size() > k){
            return;
        }

        if(sum == n && k == ve.size() ){
            res.emplace_back(ve);
            return;
        }

        for(int i = startindex ; i < nums.size() && sum + nums[i] <= n; ++i){
            ve.emplace_back(nums[i]);
            sum += nums[i];
            backtracking(nums, k, n, i + 1, sum, ve, res);
            ve.pop_back();
            sum -= nums[i];
        }
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> ve;
        vector<vector<int>> res;
        int sum = 0;
        backtracking(nums, k, n, 0, sum, ve, res);
        return res;
    }
};
// @lc code=end

int main(){
    Solution sl;
    sl.combinationSum3(3, 7);
}