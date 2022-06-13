/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fre = 1;        
        for(auto i = nums.begin(); i != nums.end() - 1 ; ++i){
            if(*i != *(i+1)){
                fre = 1;
            }else{
                ++fre;
                if(fre > 2){
                    nums.erase(i);
                    --i;
                }
            }
        }
        return nums.size();
    }
};
// @lc code=end

