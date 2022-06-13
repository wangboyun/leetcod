/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-09-01 20:33:42
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++){
            hashmap[nums[i]] = i;
        }
        for(int i = 0; i < nums.size()-2 ; i++){
            for(int j = i+1 ; j < nums.size()-1; j++){
                for(int k = j + 1; k < nums.size(); k++ ){
                    auto ptr = hashmap.find(target - nums[i] -nums[j] -nums[k]);
                    if( ptr != hashmap.end() && ptr->second > i 
                        && ptr->second > j && ptr->second > k){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(ptr->first);
                        ans.push_back(v);
                    }
                }
            }
        }
        return ans; 
    }
};
// @lc code=end

