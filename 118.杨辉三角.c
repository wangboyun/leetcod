/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-07-26 19:36:28
 * @LastEditors: Wyz
 * @LastEditTime: 2021-07-26 20:54:20
 */
/*
 * @lc app=leetcode.cn id=118 lang=c
 * 解题思路：杨辉三角的行数与列数是一致的
 * [118] 杨辉三角
 */

// @lc code=start


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * @description: 
 * @param {int} numRows  --- 表示杨辉三角的行数
 * @param {int*} returnSize -- 表示返回二维数组的行数
 * @param {int**} returnColumnSizes -- 表示返回的二维数组每行的列数
 * @return {*}
 * @author: Wyz
 */
#include <stdlib.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i,j = 0;
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(4 * numRows);
    int** ret = (int**)malloc(sizeof(int*) * numRows);
    /* 首先将每一行的第一个数与最后一个数设为1*/
    for(i = 0;i < numRows; i++){
        (*returnColumnSizes)[i] = i+1; //表示每一行的列数
        ret[i] = (int*)malloc (sizeof(int) * (i+1));
        ret[i][0] = 1;
        ret[i][i] = 1;
    }
    /* 根据公式计算其余值 */
    for(i = 2; i < numRows ; i++){
        for(j = 1 ; j < i ; j++){
            ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
        }
    }
    return ret;
}
// @lc code=end

