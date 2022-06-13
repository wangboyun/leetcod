/*
 * @Description: 采用哈希表操作，
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-02 10:53:50
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            hashmap[nums[i]] = i;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            auto pos = hashmap.find(target - nums[i]);
            if( pos!= hashmap.end() && i != pos->second ){
                ans.push_back(i);
                ans.push_back(pos->second);
                return ans;
            }
            
        }
        return ans;
    }
};
// @lc code=end

