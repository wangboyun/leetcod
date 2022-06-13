/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-02 19:33:20
 */
/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */
#include<algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for(i = 0 ; i < nums.size() ; ++i){
            if(i != nums[i]){
                break;
            }
        }
        return i;
    }
};
// @lc code=end

