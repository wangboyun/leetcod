/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-08-30 21:14:07
 */
/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

#include <iterator>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>  hashmap;
        for(int i = 0 ; i < nums.size() ; i++){
            if(hashmap.find(nums[i]) == hashmap.end() || i - hashmap[nums[i]] > k){
                hashmap[nums[i]]= i;
            }
            else {
                return true;
            }
        }
        return false; 
    }
};
// @lc code=end

