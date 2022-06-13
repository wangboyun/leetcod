/*
 * @lc app=leetcode.cn id=171 lang=c
 *
 * [171] Excel表列序号
 */

// @lc code=start
#include <string.h>
#include <math.h>

int titleToNumber(char * columnTitle){
    int len = strlen(columnTitle);
    int i ,res = 0;
    for(i = 0 ; i < len-1 ; i++){
        res += ((*(columnTitle+i) -'A') + 1)
        * ((int)pow(26,(len - i -1)));
    }
    res += ((*(columnTitle + len-1) -'A') + 1);
    return res;
}
// @lc code=end

