/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:

    void backtracking(vector<int>& nums , bool used[],int index , vector<int>& ve , vector<vector<int>>& res){
        if(index > nums.size() - 1){
            res.emplace_back(ve);
            return;
        }

        ///去重操作(不重复的全排列)
        for(int i = 0; i < nums.size() ; ++i){
            if(i > 0 && nums[i] == nums[i-1] 
            && used[i-1] == true){
                continue;
            }
                
            if(!used[i]){
                used[i] = true;
                ve.emplace_back(nums[i]);
                backtracking(nums, used, index + 1,ve , res);
                ve.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ve;
        vector<vector<int>> res;
        bool used[8] = {false};
        sort(nums.begin(),nums.end());
        backtracking(nums, used, 0, ve, res);
        return res;
    }
};
// @lc code=end

int main(){
    vector<int> nums = {1,1,2};
    Solution sl;
    sl.permuteUnique(nums);
}