/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int i = 0;
        for(; i < s.size() -1 ; ++i){
            auto it = s.find(s[i] , i+1);
            if(it == s.npos){
                return i;
            }
            
        }
        if( i == s.size() -1)
            return i;
        return -1;
    }
};
// @lc code=end

