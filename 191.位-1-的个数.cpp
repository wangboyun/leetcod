/*
 * @Description: 最高效的求 1 个数的方法
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-01 17:15:37
 */
/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

#include <iostream>
// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(; n ; ++res){
            n &= n - 1;
        }
        return res;
    }
};
// @lc code=end

