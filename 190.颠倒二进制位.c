/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-08-10 21:51:30
 * @LastEditors: Wyz
 * @LastEditTime: 2021-08-12 11:45:53
 */
/*
 * @lc app=leetcode.cn id=190 lang=c
 *
 * [190] 颠倒二进制位
 */


// @lc code=start


typedef unsigned int uint32_t;
uint32_t half_num(uint32_t n , int count)
{
    uint32_t a = 1;
    uint32_t res = 0;
    int i = count;
    while((--i) > 0){
        uint32_t temp ;
        temp = (n & a) << i;
        a <<= 1;
        i--;
        res |= temp;
    }
    return res;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t temp = n;
    uint32_t res = 0;
    int count = 32;
    while(count > 1){
        res += half_num(temp,count);
        count /= 2;
        temp >>= count;
    }
    res += (n >> 31 );
    return res;
}
// @lc code=end

