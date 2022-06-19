/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

/// 采用动态规划
// 递推公式 dp[i] = dp[ i - 1] + dp[i - 2]

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)  return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3 ; i <= n ; ++i){
            dp[i] = dp[ i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end

