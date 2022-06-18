/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    
    void backtracking(vector<int>& candidates, int target, int sum , int startindex, bool used[], vector<int>& ve,vector<vector<int>>& res){

        if (sum == target){
            res.emplace_back(ve);
            return;
        }

        for(int i = startindex ; i < candidates.size() && sum + candidates[i] <= target; ++i){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) 
                continue;

            used[i] = true;
            sum += candidates[i];
            ve.emplace_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1, used , ve, res);
            ve.pop_back();
            sum -= candidates[i];
            used[i] = false;
            
            
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ve;
        int sum = 0;
        bool used[100] = {false};
        sort(candidates.begin(), candidates.end());
        backtracking(candidates,target,sum,0,used,ve,res);
        return res;
    }
};
// @lc code=end

