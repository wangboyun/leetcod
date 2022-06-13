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

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        int pre = 0 ; 
        int cur = 1; 
        int nex = pre + cur;
        while(n >= 2){
            pre = cur;
            cur = nex;
            nex = pre + cur;
            n--;
        }
        return cur;
    }
};
// @lc code=end

