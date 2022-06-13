/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 */

// @lc code=start

/* 思路
*这题本质上就是一个26进制的转换过程
*通过反转字符串得到结果 
*columnNumber <= 231 - 1 所以最多有 7位，示例4
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 将数字转换为对应的字符 */
char numtochar(int num){
    return ((num -1) + 'A');
}

char * convertToTitle(int columnNumber){
    int i = 0;   //除数
    char ans[8] = {0};
    int nmax = 0;
    while(columnNumber > 26 ){
        /* columnNumber 为26的倍数时*/
        if(columnNumber % 26 == 0){
            ans[nmax] = numtochar(26);
            nmax++ ;
            columnNumber -= 26;
            columnNumber = columnNumber / 26;
        }
        /* columnNumber 不为26的倍数时*/
        else{
            ans[nmax] = numtochar(columnNumber % 26);
            nmax++ ;
            columnNumber = columnNumber / 26;
        }
        
    }
    ans[nmax] = numtochar(columnNumber);
    
    char * res = malloc(sizeof(char)*(nmax+2));
    memcpy(res, ans, (nmax+2));
    /* 反转字符串 */
    int left = 0;
    int right = nmax;
    while(left < right){
        char temp = *(res + right);
        *(res + right) = *(res + left);
        *(res + left) = temp;
        left++;
        right--;
    }
    return res;
}
// @lc code=end

