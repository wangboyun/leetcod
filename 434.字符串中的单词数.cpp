/*
 * @Description: 注意的点是连续的空格
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-03 20:30:03
 */
/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */
#include <cctype>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        if(s.empty()){
            return ans;
        }
        for(int i = 0 ; i < s.size() ; ++i){
            if( i == 0 && i < s.size() -1 && isspace(s[i]) && !isspace(s[i+1])){
                ++ans;
            }else if( i > 0 && i == s.size() -1 && isspace(s[i]) && !isspace(s[i- 1])){
                ++ans;
            }else if( i > 0 && i < s.size() -1 && isspace(s[i]) && !isspace(s[i- 1])){
                ++ans;
            }
        }
        if(!isspace(s[s.size()- 1]))
            return ans+1;
        return ans;
    }
};
// @lc code=end

