/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start

/*  排序，最中间的数即为要求的数 (冒泡排序超时了)
    更改为快排(还是超时)；
    更换为c库自带的排序qsort();
*/

#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums[numsSize/2];
}
// @lc code=end

