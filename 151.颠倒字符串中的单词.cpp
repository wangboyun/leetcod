/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */
#include <cctype>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    void resverse(string& s, int start, int end){
        for(int i = start, j = end; i < j; ++i, --j){
            swap(s[i], s[j]);
        }
    }

    // 去除多余的空格
    void removeExpSpace(string& s){
        int slowIndex = 0, fastIndex = 0; 
        while(fastIndex < s.size() && s[fastIndex] == ' '){
            fastIndex++;
        }
        for(; fastIndex < s.size(); ++fastIndex){
            if(fastIndex - 1 > 0 && s[fastIndex] == s[fastIndex - 1] 
            && s[fastIndex] == ' '){
                continue;
            }else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }

    string reverseWords(string s) {
        string str = s;
        removeExpSpace(str);
        int len = str.size();
        resverse(str, 0, len - 1);
        int start = 0 ; 
        for(int i = 0 ; i < len; ++i){
            if(str[i] == ' '){
                resverse(str, start, i - 1);
                start = i + 1;
            }
        }
        resverse(str, start, len- 1);
        return str;
    }
};
// @lc code=end

