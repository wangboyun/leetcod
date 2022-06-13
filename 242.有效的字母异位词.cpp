/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

/// 利用
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t ;
    }
};
// @lc code=end

