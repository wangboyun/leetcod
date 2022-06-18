/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    void backtracking(vector<int>& nums,vector<int>& ve, int  index ,vector<vector<int>>& res, bool visit[]){
        if(index > nums.size() - 1 ){
            res.emplace_back(ve);
            return ;
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if(visit[i]){
                continue;
            }
            ve.emplace_back(nums[i]);
            visit[i] = true;
            backtracking(nums,ve,index+1,res,visit);
            ve.pop_back();
            visit[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ve;
        vector<vector<int>> res;
        bool visit[6] = {false};
        backtracking(nums,ve,0,res,visit);
        return res;
    }
};
// @lc code=end

