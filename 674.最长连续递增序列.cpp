/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size =  nums.size();
        if(size == 0 || size == 1){
            return size;
        }
        int len = 1;
        int ans = 1;
        for(int i = 0 ; i < size - 1; ++i ){
            if( nums[i] < nums[i+1]){
                len++;
            }else {
                len = 1;
            }
            ans = ::max(ans , len);
        }
        return ans;
    }
};
// @lc code=end

