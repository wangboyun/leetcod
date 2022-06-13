/*
 * @lc app=leetcode.cn id=122 lang=c
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start


int maxProfit(int* prices, int pricesSize){
    int ans = 0;
    int res = 0;
    int i ,j;
    for(i = 0 ; i < pricesSize ; i++){
        for(j = i + 1 ; j < pricesSize ; j++){
            if(prices[j] - prices[i] > 0){
                if(res < prices[j] - prices[i]){
                    res = prices[j] - prices[i];
                    if(j == pricesSize -1){
                        ans += res;
                        return ans;
                    }
                }
                else {
                    ans += res;
                    res = 0;
                    i = j - 1;
                    break;
                }
            }
            else{
                ans += res;
                res = 0;
                i = j - 1;
                break;
            }
        }
    }
    return ans;
}
// @lc code=end

