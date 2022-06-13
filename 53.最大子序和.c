/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-07-24 17:38:50
 * @LastEditors: Wyz
 * @LastEditTime: 2021-07-25 20:45:16
 */
/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 */

// @lc code=start

int max(int a , int b)
{
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize){
    int sum = 0;
    int ans = nums[0];
    int i = 0;
    for(i = 0 ; i < numsSize ;  i++){
        if(sum > 0)     /*如果sum即与之后一个数之后大于 0 即有益 可以保留*/
        {
            sum += nums[i]; 
        }
        else{
            sum = nums[i];  /* 如果小于0 直接跳过这个数*/
        }
        ans = max(sum,ans);
    }
    return ans;
}
// @lc code=end

