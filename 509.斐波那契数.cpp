/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-10-26 20:02:40
 */
/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// 利用动态规划接一下

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if( n < 2){
            return n;
        }
        int dp [2];
        dp[0] = 0;
        dp[1] = 1;
        int res;
        for(int i = 2 ; i <= n ; ++i){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};
// @lc code=end

