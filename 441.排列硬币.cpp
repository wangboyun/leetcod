/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution {
public:
    long int calculate( long int n){
        return ((1 + n) * n / 2 );
    }

    int arrangeCoins(int n) {
        long int left = 1 ;
        long int right = n;
        while(left < right) {
            long int mid = (left  + right) / 2;
            if(calculate(mid) == n  || (calculate(mid) < n && calculate(mid + 1) > n)){
                return mid;
            }else if(calculate(mid) > n){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

