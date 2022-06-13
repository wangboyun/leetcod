/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-03 20:02:40
 */
/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

#include <set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> set;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; ++i){
            set.insert(nums[i]);
        }
        for(auto i : set){
            ans.emplace_back(i);
        }
        if(ans.size() < 3){
            return ans[ans.size() - 1];
        }
        return ans[ans.size() - 3];
    }
};
// @lc code=end

