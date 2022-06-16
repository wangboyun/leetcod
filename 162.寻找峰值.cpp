/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1){
            return 0;
        }else if(len == 2){
            if(nums[0] > nums[1]){
                return 0;
            }else{
                return 1;
            }
        }
        vector<int> que {nums[0]};
        for(int i = 1 ; i < len; ++i){
            if(nums[i] < que.back()){
                return i - 1;
            }
            while(que.size() && nums[i] > que.back()){
                que.pop_back();
            }
            que.emplace_back(nums[i]);
        }
        return len - 1;
    }
};
// @lc code=end

int main(){
    vector<int> num{1,2,1,3,5,6,4};
    Solution sl;
    sl.findPeakElement(num);
}
