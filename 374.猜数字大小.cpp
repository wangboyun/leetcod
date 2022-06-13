/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int  left = 0 ;
        long long int  right = n;
        long long int  tem = 0;
        if(guess(n) == 0)
            return n;
        while (1){
            tem = (left + right) >> 1;
            if(guess(tem) == 0){
                return tem;
            }else if (guess(tem) > 0) {
                left = tem ;
                continue;
            }else{
                right = tem ;
            }
        }
    }


};
// @lc code=end

