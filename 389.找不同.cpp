/*
 * @Description: 
 * @Version: 0.1
 * @Autor: Wyz
 * @Date: 2021-11-02 21:22:03
 */
/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

#include <string>
#include <set>

using namespace std;
// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        multiset<char> set;
        if(s.empty())
            return t.at(0);
        for(int i = 0 ; i < s.size() ; ++i){
            set.insert(s[i]);
        }
        for(int i = 0 ; i < t.size() ; ++i){
            if(set.find(t[i]) == set.end()){
                return t[i];
            }else {
                set.erase(set.find(t[i]));
            }
        }
        return ' ';
    }
};
// @lc code=end

