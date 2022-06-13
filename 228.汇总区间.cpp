/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string s;
        int start  = 0;
        long long int def = 0;
        if(nums.size() == 0){
            return ans;
        }

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if((nums[i+1] - 1 ) > nums[i] ){
                if(i != start){
                    s = to_string(nums[start]) + "->" + to_string(nums[i]);
                }else {
                    s = to_string(nums[start]);
                }
                start = i + 1;
                ans.emplace_back(s);
            }
        }
        if(start == nums.size()-1){
            ans.emplace_back(to_string(nums[nums.size()-1]));
        }else {
            s = to_string(nums[start]) + "->" + to_string(nums[nums.size()-1]);
            ans.emplace_back(s);
        }
        return ans;
    }
};
// @lc code=end

