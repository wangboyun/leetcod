/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-08-10 21:35:45
 * @LastEditors: Wyz
 * @LastEditTime: 2021-08-11 20:03:28
 */
 /*
 * @lc app=leetcode.cn id=172 lang=c
 *
 * [172] 阶乘后的零
 */

// @lc code=start

/* 
思路 阶乘为0 必然要有 5 找有几个5
5 -- 1
10 -- (5 , 2 * 5) -- 2个5
15 -- （5 ， 2*5 ， 3*5） -- 3个5
25 -- （5 ， 2*5 ， 3* 5 ， 4 * 5， 5 *5） --6个5
*/

int trailingZeroes(int n){
    int ans = 0 ; 
    while(n/5){
        ans += n/5;
        n /= 5;
    }
    return ans;
}
// @lc code=end

