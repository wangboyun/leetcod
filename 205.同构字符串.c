/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-08-12 12:00:28
 * @LastEditors: Wyz
 * @LastEditTime: 2021-08-12 20:45:10
 */
/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>


/* 找相同字符的下标 index (超时了)*/
bool isIsomorphic(char * s, char * t){
    int i ,j= 0;
    int len = strlen(s);
    for(i = 0 ; i < len -1 ; i++){
        for(j = i + 1 ; j < len ; j ++){
            if(*(s+i) == *(s + j)){
                if(*(t+i) == *(t + j)){
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                if(*(t+i) != *(t + j)){
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        
    }
    
    return true;

}
// @lc code=end

