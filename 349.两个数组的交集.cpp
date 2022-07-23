/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 去除
        set<int> n1_set;
        set<int> n2_set;
        vector<int> ans;
        for(int i : nums1){
            n1_set.emplace(i);
        }
        for(int i : nums2){
            n2_set.emplace(i);
        }

        for(auto i : n1_set){
            if(n2_set.find(i) != n2_set.end()){
                ans.emplace_back(i);
            }
        }

        return ans;
    }
};
// @lc code=end

