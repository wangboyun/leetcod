/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Wyz
 * @Date: 2021-07-25 20:45:30
 * @LastEditors: Wyz
 * @LastEditTime: 2021-07-25 22:08:19
 */
/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start



#include <string.h>
int lengthOfLastWord(char * s){
    int len,res,i = 0; 
    int flag = 0;
    char *ptr = NULL;
    
    if(s == NULL ){
        return 0;
    }
    len = strlen(s);
    for(i = 0 ; i < len ; i++){
       if((*s - ' ' ) == 0){
           s++;
           flag++;
       }
    }
    if(flag == len)
        return 0;
    ptr = strtok(s, " ");
    while(ptr != NULL)
    {
        res = strlen(ptr);
        ptr = strtok(NULL," ");
    }
    return res;
}
// @lc code=end

