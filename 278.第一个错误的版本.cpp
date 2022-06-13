/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-02 19:46:20
 */
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int left = 1 ; 
        long long int right = n;
        int mid = 0;
        while(left <= right){
            mid =  (left + right) >> 1;
            if(isBadVersion(mid)){
                if(mid > 1 && isBadVersion(mid - 1)){
                    right = mid - 1;
                }
                else {
                    break;
                }
            }
            else
                left = mid + 1;
        
        }
        return mid;
    }
};
// @lc code=end

