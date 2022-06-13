/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int* getRow(int rowIndex, int* returnSize){
    int i,j = 0;
    *returnSize = rowIndex+1;                /* 返回的数组大小为rowIndex */
    int ** res = (int **)malloc(sizeof(int *) * (rowIndex+1));
    /*将 二维数组开辟出来 把每一行的第一个数与最后一个数置为 1*/
    for (i = 0; i <= rowIndex; i++) {
        res[i] = (int *)malloc(sizeof(int) * (i+1));
        res[i][0] = 1;
        res[i][i] = 1;
    }

    /* 将其余的数据填充好 */
    for(i = 2 ; i <= rowIndex ; i++){
        for(j = 1 ; j < i; j++){
            res[i][j] = res[i-1][j-1] + res[i-1][j];
        }
    }

    return res[rowIndex];
}
// @lc code=end

