/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /// 利用dp数组来解决
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int dp[len][2] ;
        dp[0][0] = 0 - prices[0] ; /// 买入花费的钱
        dp[0][1] = 0;      /// 卖出赚的利润

        for(int i = 1; i < len ; ++i){
            dp[i][0] = max(-prices[i] , dp[i - 1][0]);
            dp[i][1] = max(prices[i] + dp[i - 1][0] , dp[i - 1][1]);
        }
        return  dp[len - 1][1];
    }
};
// @lc code=end


/// 方法1
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> leftmin(prices.size() , 0);
        vector<int> rightmax(prices.size() , 0);
        int size = prices.size();
        int maxprofit = 0;

        leftmin[0] = prices[0];
        for(int i = 1 ; i < size ; ++i){
            leftmin[i] = min(prices[i] , leftmin[i - 1]);
        }

        rightmax[size - 1] = prices[size - 1];
        for(int i = size - 2 ; i >= 0 ; --i){
            rightmax[i] = max(prices[i] , rightmax[ i + 1]);
        }

        for(int i = 0 ; i < size ; ++i){
            int count = rightmax[i] - leftmin[i];
            if(count > 0){
                maxprofit = max(maxprofit , count);
            }
        }
        return maxprofit;
    }
};