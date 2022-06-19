/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /// dp[i][0] -- 第i天持有股票时的钱
    /// dp[i][1] -- 第i天不持有股票时的钱

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int dp[len][2];
        dp[0][0] = 0 - prices[0];
        dp[0][1] = 0;

        for(int i = 1 ; i < len ; ++i){
            dp[i][0] = max(dp[i - 1][0] , dp[ i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1] , dp[i - 1][0] + prices[i]);
        }
        /// 返回的是不持有的状态的最大值
        return  dp[len - 1][1];
    }
};
// @lc code=end

