/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDig(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int addDigits(int num) {
        int ans = num;
        while (ans >= 10){
            ans = addDig(ans);
        }
        return ans;
    }
};
// @lc code=end

