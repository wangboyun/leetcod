/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// 利用快慢指针的思想进行



// @lc code=start
class Solution {
public:

    int bitsum(int n){
        int sum = 0;
        while(n > 0){
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n ; int fast = n;
        do {
            // 慢部分走
            slow = bitsum(slow);

            fast = bitsum(fast);
            fast = bitsum(fast);
        }while (slow != fast);
        
        return slow == 1;
    }
};
// @lc code=end

