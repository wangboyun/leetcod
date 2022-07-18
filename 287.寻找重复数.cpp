/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int , int> map;
        for(auto i : nums){
            map[i] ++;
        }
        for(auto m : map){
            if(m.second > 1){
                return m.first;
            }
        }
        return 0;
    }
};
// @lc code=end

