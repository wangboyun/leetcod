/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-08-12 20:46:45
 * @LastEditors: Wyz
 * @LastEditTime: 2021-08-12 21:52:02
 */
/*
 * @lc app=leetcode.cn id=219 lang=c
 *
 * [219] 存在重复元素 II
 */

// @lc code=start


#include <stdlib.h>

int cmp ( const void *a , const void *b ){
    return *(int *)a - *(int *)b;
}

// 正常处理超时
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int i  = 0;
    int count = 0;
    if(numsSize == 1)
        return false;
    if(numsSize < k){
        qsort(nums,numsSize, sizeof(int),cmp);
        for(i = 0 ; i < numsSize-1 ; i++){
            if(nums[i] == nums[i+1]){
                return true;
            }
            else {
                continue;
            }
        }
        return false;
    }
    if(numsSize == k){
        if(nums[0] == nums[k -1])
            return true;
        else
            return false;
    }
    for(i = 0 ; i < numsSize-1 ; i++){
        while(nums[i] != nums[i+count] && count < k){
            count++;
        }
        if(count == k){
            continue;
        }
        else {
            return true;
        }
    }
    return false;
}
// @lc code=end

