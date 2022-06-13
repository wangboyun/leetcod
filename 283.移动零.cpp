/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-02 20:24:04
 */
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i  = 0;
        while ( i  < size){
            if(nums[i] == 0 ){
                nums.emplace_back(0);
                nums.erase(nums.begin() + i);
                size--;
                continue;
            }
            ++i;
        }

    }
};
// @lc code=end

