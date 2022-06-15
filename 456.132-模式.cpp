/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 模式
 */
#include <iterator>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> sta;
        int right = -1e9;
        for(int i = nums.size() - 1 ; i >= 0 ; --i){
            if(nums[i] < right){
               return true;
            }
            while(!sta.empty() && nums[i] > sta.top()){
                right = sta.top();
                sta.pop();
            }
            sta.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end

int main(){
    vector<int> nums {-1,3,2,0};
    Solution sl;
    sl.find132pattern(nums);
}