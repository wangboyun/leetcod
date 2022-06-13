/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start

#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left,right = 0;
    *returnSize = 2;
    int *ans = (int *)malloc(sizeof(int) * (*returnSize));
    left = 0;
    right = numbersSize - 1;
    while (numbers[left] + numbers[right] != target) {
        if(numbers[left] + numbers[right] > target){
            right = right -1;
        }
        else if (numbers[left] + numbers[right] < target) {
            left = left + 1;
        }
        else 
            break;
    }
    ans[0] = left + 1;
    ans[1] = right + 1;
    return ans;
}
// @lc code=end

