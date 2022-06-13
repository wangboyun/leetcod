/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-07-26 21:21:46
 * @LastEditors: Wyz
 * @LastEditTime: 2021-07-27 21:19:46
 */
/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
/**
 * @description: 找最小值的下标
 * @param {int} *prices
 * @param {int} pricesSize
 * @return {*}
 * @author: Wyz
 */
int max (int a , int b){
    return a > b ? a : b ;
}


int maxProfit(int* prices, int pricesSize){
    int i , j = 0;
    int buyin,ans = 0;
    for(i = 0 ; i < pricesSize ; i++){
        for(j = i +1 ; j < pricesSize ; j++){
            buyin = prices[i];
            if(prices[j] <= buyin){
                break;
            }
            else 
                ans = max(ans , (prices[j] - buyin));
        }
    }
    return ans;
}
// @lc code=end

