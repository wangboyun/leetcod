/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        int start = 0;
        int end = 0;
        bool flag = false; 
        sort(temp.begin(), temp.end());
        for(int i = 0 ; i < nums.size(); ++i){
            if(nums[i] != temp[i] && flag == false){
                start = i;
                flag = true;
            }
            else if(nums[i] != temp[i] && flag){
                end = max(end , i);
            }
        }
        if(end != start){
            return end - start + 1;
        }
        return 0;
    }
};
// @lc code=end

