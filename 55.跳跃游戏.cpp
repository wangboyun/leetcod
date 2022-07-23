/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums, int start, int end){
        for(int i = start ; i < end; ++i ){
            if(end == nums.size() && nums[i] >= (end - start)){
                return true;
            }

            if(nums[i] > end - start){
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        int start = 0; int end = 0;
        int len = nums.size();
        if(len == 1 && nums[0] == 0){
            return true;
        }
        for(int i = 0 ; i < len; ++i){
            if(i < len - 1 && nums[i] == 0 && nums[i + 1] != 0){
                end = i;
                if(canJump(nums, start,end) == false){
                    return false;
                }else{
                    start = end;
                }
            }else if(i == len - 1 && nums[i] == 0){
                end = i;
                if(canJump(nums, start,end) == false){
                    return false;
                }else{
                    start = end;
                }
            }
        }
        return true;
    }
};
// @lc code=end

int main(){
    vector<int> nums = {2,0,0};
    Solution sl;
    sl.canJump(nums);
}